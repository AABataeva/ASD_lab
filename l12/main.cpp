#include <iostream>                 //внешняя многофазная сортировка
#include <vector>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

class Node {
public:
    int element;
    int index;
    Node(int ele, int idx) {
        element = ele;
        index = idx;
    }
};

class cmp {
public:
    bool operator() (Node l, Node r) {
        return l.element > r.element;
    }
};

void mergeFiles(int &file_count) {
    vector<ifstream> input_files(file_count);

    for(int i = 0; i < file_count; ++i) {
        string file_name = to_string(i) + ".txt";
        input_files[i].open(file_name);
    }
    ofstream output;
    output.open("output.txt");

    priority_queue<Node, vector<Node>, cmp> pq;
    int num;
    for(int i = 0; i < file_count; ++i) {
        input_files[i] >> num;

        Node N(num, i);
        pq.push(N);
    }
    while(pq.size()) {
        Node node = pq.top();
        pq.pop();
        output << node.element << " ";
        if(input_files[node.index] >> num) {
            node.element = num;
            pq.push(node);
        }
    }

    for(int i = 0; i < file_count; ++i) {
        string file_name = to_string(i) + ".txt";
        input_files[i].close();
    }
    output.close();
}

void createRAMFiles(ifstream &inp_file, int ram_size, int &file_count) {
    ofstream out_file;
    vector<int> nums;
    bool more_input = true;
    int num_count = 0, num;
    string file_name = "";
    while(more_input) {
        nums.clear();
        while(num_count < ram_size) {
            if(inp_file >> num) {
                nums.push_back(num);
                num_count++;
            }
            else {
                more_input = false;
                break;
            }
        }
        if(nums.empty()) break;
       // sort (nums.begin(), nums.end());
        file_name = to_string(file_count) + ".txt";

        out_file.open(file_name);
        for(int i = 0; i < nums.size(); ++i) {
            out_file << nums[i] <<" ";
        }
        out_file.close();

        num_count = 0;

        file_count++;
    }
}

int main()
{
    ifstream inp_file;
    inp_file.open("input.txt");
    int ram_size = 5;
    int file_count = 0;
    createRAMFiles(inp_file, ram_size, file_count);
    mergeFiles(file_count);

}
