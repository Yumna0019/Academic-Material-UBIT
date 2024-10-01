#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}
int main()
{
    int arr[] = {1, 4, 3, 5, 2, 6, 8, 7};
    selection_sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
}