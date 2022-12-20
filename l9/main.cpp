#include <iostream>              //������������� �����
#define ARR_SIZE 25
using namespace std;

void heapify(int arr[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[max]) // ���� ����� ������� ������ max
        max = l;

    if (r < n && arr[r] > arr[max]) // ���� ������ ������� ������, ��� ����� ������� ������� �� ������ ������
        max = r;

    if (max != i) {                  // ���� ����� ������� ������� �� max
        swap(arr[i], arr[max]);

        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)                    //�������� ����������
{
    for (int i = n / 2 - 1; i >= 0; i--)           //�������������� ������
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {           //��������� ��������
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArr(int arr[], int n)             //����� �������
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
