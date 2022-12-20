#include <iostream>              //пирамедальный метод
#define ARR_SIZE 25
using namespace std;

void heapify(int arr[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[max]) // Если левый элемент больше max
        max = l;

    if (r < n && arr[r] > arr[max]) // Если правый элемент больше, чем самый большой элемент на данный момент
        max = r;

    if (max != i) {                  // Если самый большой элемент не max
        swap(arr[i], arr[max]);

        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)                    //основная сортировка
{
    for (int i = n / 2 - 1; i >= 0; i--)           //перегруппируем массив
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {           //извлекаем элементы
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArr(int arr[], int n)             //вывод массива
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] <<endl;

}

int main()
{
    int arr[]={3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4};
    heapSort(arr, ARR_SIZE);
    printArr(arr, ARR_SIZE);
}
