#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[] = {1, 4, 3, 5, 2, 6, 8, 7};
    bubble_sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
}