#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Tree
{
public:
    int value;
    Tree* parent;       // поле ссылка на родителя
    Tree* left;          // поле ссылка на левого потомка
    Tree* right;         // поле ссылка на правого потомка
    string string;               // для линейно-скобочной записи.
    Tree(const int v, Tree* p){
        value = v;
        parent = p;
    }

    Tree(){}

    Tree(std::string str){
        string = str;
    }

    void add(const int v){
        if (v > value){
            if (right == nullptr){
                right = new Tree(v, this);
            }
            else{
                right->add(v);
            }
        }
        else{
            if (left == nullptr){
                left = new Tree(v, this);
            }
            else{
                left->add(v);
            }
        }
    }

    std::string toString(int value){                      // переводит число в строку
       std::string result;
        if (value > 9){
            result += char(value / 10 + 48);
            result += char(value % 10 + 48);
        }
        else{
            result += char(value + 48);
        }

        return result;
    }


    void print(Tree* tree){                         // переводит дерево в линейно-скобочуню запись
        string += toString(tree->value);
        if (tree->left != nullptr || tree->right != nullptr){
            string += '(';
            if (tree->left != nullptr){
                print(tree->left);
            }
            string += ',';
            if (tree->right != nullptr){
                print(tree->right);
            }
            string += ')';
        }

    }

    void Print(){print(this);}

    bool isDigital(const char elem){return (elem >= '0' && elem <= '9') ? true : false;}

    Tree parse(std::string str){
        Tree result;
        int index;
        if (isDigital(str[0]) && isDigital(str[1])){
            int val = (str[0] - 48) * 10 + str[1] - 48;
            result.value = val;
            index = 2;
        }
        else if (isDigital(str[0]) && !isDigital(str[1])){
            int val = str[0] - 48;
            result.value = val;
            index = 1;
        }

        for (int i = index; i < str.size() - 1;){
            if (isDigital(str[i]) && isDigital(str[i + 1])){
                int value = (str[i] - 48) * 10 + str[i + 1] - 48;
                result.add(value);
                i += 2;
            }
            else if (isDigital(str[i]) && !isDigital(str[i + 1])){
                int value = str[i] - 48;
                result.add(value);
                i++;
            }
            else{
                i++;
            }
        }

        return result;
    }
};
void direct(vector<int>& v, Tree* tree){          //отличие от прошлой в том, что тут мы используем стек, созданный из указателей на узлы,а также главный принцип обхода дерева в том,
                                                   // что ни одна вершина не будет пропущена и не будет обработана дважды
    stack <Tree*> s;
    s.push(nullptr);                              //пустой указатель
    Tree* tempTree = tree;                        //сохраняем копию дерева, по которому совершаем обход
    do{
        if (tempTree != nullptr){                 //если полученный указатель не пустой, тогда вставляем его в стек
            s.push(tempTree);
            v.push_back(tempTree->value);
            tempTree = tempTree->left;            //двигаемя влево
        }
        else{
            if (s.top() == nullptr){              //если имеется пустой указатель, завершаем обход
                break;
            }
            tempTree = s.top();                   //рассматриваем верхушку стека
            s.pop();
            tempTree = tempTree->right;           //двигаемся вправо
        }
    } while (true);
}

void center(vector<int>& v, Tree* tree){          //алгоритм аналогичный
    stack <Tree*> s;
    s.push(nullptr);
    Tree* tempTree = tree;
    do{
        if (tempTree != nullptr){
            s.push(tempTree);
            tempTree = tempTree->left;
        }
        else{
            if (s.top() == nullptr){
                break;
            }
            tempTree = s.top();
            s.pop();
            v.push_back(tempTree->value);
            tempTree = tempTree->right;
        }
    } while (true);
}

void reverse(vector<int>& v, Tree* tree){
    stack <Tree*> s;
    Tree* lastVisited = nullptr;                     // Используем указатель последнего посещённого узла
    Tree* tempTree = tree;
    while (!s.empty() || tempTree != nullptr){
        if (tempTree != nullptr){
            s.push(tempTree);
            tempTree = tempTree->left;
        }
        else{
            Tree* topTree = s.top();
            if (topTree->right != nullptr && lastVisited != topTree->right){
                tempTree = topTree->right;
            }
            else{
                v.push_back(topTree->value);
                lastVisited = s.top();
                s.pop();
            }
        }
    }
}


int main()
{
    vector <int> directValues;
    vector <int> centerValues;
    vector <int> reverseValues;
    int maxElem;
    string str = "8(3(1,6(4,7)),10(,14(13,)))";
    Tree tree;
    tree = tree.parse(str);
    Tree newTree = tree;
    newTree.Print();
    direct(directValues, &newTree);    //прямой обход
    center(centerValues, &newTree);     //кольцевой обход
    reverse(reverseValues, &newTree);    //обратный обход
    for (auto& value : reverseValues){cout << value << "\t";}
    return 0;
}
