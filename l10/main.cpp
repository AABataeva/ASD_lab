#include <iostream>                 //метод сливания
#define ARR_SIZE 25
using namespace std;

void merge(int arr[], int l, int m, int r)       //где m=mid(середина),l=left(левая часть),r=right(правая)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1], *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){             //основная сортировка
    if(l>=r){
        return;
    }
    int m =l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void printArr(int arr[], int size)          // вывод массива
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
}

int main()
{
    int arr[]={3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4};
    mergeSort(arr, 0, ARR_SIZE - 1);
    printArr(arr, ARR_SIZE);
    return 0;
}
