#include <iostream>               //методом прочесывания
#include <vector>


int main() {
    std::vector<int> arr = {3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4,2,45,6};
    int s1 = arr.size() - 1;       // шаг сортировки
    float factor = 1.2473309;      // фактор уменьшения
    while (s1 >= 1)
    {
        for (int i = 0; i + s1 < arr.size(); i++)
        {
            if (arr.at(i) > arr.at(i + s1))
            {
                std::swap(arr.at(i), arr.at(i + s1));
            }
        }
        s1 =  s1 / factor;
    }
    for(int i = 0 ; i < arr.size(); i++){
        std::cout << arr.at(i) << std::endl;
    }
    return 0;
}
