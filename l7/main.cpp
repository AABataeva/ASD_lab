#include <iostream>                  //методом Шелла
#define ARR_SIZE 25
using namespace std;

int sort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
                arr[j] = temp;
        }
    }
    return 0;
}

void printArr(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int arr[]={3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4};
    sort(arr, ARR_SIZE);
    printArr(arr, ARR_SIZE);

    return 0;
}

