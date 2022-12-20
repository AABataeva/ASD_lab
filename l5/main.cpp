#include <iostream>               //метод вставками 
#include <vector>

int main() {
    std::vector<int> arr = {3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4,2,45,6};
    for(int i = 1; i < arr.size() ; i++){
        for(int j = i; j > 0 && arr.at(j-1) > arr.at(j); j--){
            std::swap(arr.at(j-1), arr.at(j));
        }
    }
    for(int i = 1; i < arr.size() ; i++){
        std::cout << arr.at(i) << std::endl;
    }
    return 0;
}
