#include <iostream>               //быстрый метод
#define ARR_SIZE 25
using namespace std;

void swap(int* a, int* b)            //реализуем обмен переменных
{
   int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)              //основная сортировка
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(int arr[], int size)              //вывод массива
{
    for (int i = 0; i < size; i++)
        cout << arr[i] <<endl;
}

int main()
{
    int arr[]={3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4};
    quickSort(arr, 0, ARR_SIZE - 1);
    printArr(arr, ARR_SIZE);
    return 0;
}
