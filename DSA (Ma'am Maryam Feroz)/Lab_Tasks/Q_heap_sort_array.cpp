#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    if (lc < size && arr[lc] > arr[largest])
    {
        largest = lc;
    }
    if (rc < size && arr[rc] > arr[largest])
    {
        largest = rc;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {20,30,10,80,50,25,18,97,40};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}