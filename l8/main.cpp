#include <iostream>           //поразрядный метод
using namespace std;

int maX(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
        max = arr[i];
    return max;
}
void firstSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
 count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
 count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void twoSort(int arr[], int n)
{
    int m = maX(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        firstSort(arr, n, exp);
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
int main()
{
    int arr[] = {3,246,64,2,5,67,8,8,3,36,35,2,4,5,88,6,100,33,65,8,9,790,75,4,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    twoSort(arr, n);
    printArr(arr, n);
    return 0;
}
