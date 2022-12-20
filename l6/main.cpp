#include <iostream>                  //метод посредством выбора
#include <vector>

int main() {
    std::vector<int> arr = {3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4,2,45,6};
    for(int i = 0; i < arr.size() - 1; i++ ){
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr.at(j) < arr.at(min))
            {
                min = j;
            }
        }
        if(min != i){
            std::swap(arr.at(i),arr.at(min));
        }
    }
    for(int i = 0; i < arr.size(); i++ ){
        std::cout << arr.at(i) << std::endl;
    }

    return 0;
}
