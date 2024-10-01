#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int hold = arr[i];
        int gap = i - 1;
        while (gap >= 0 && arr[gap] > hold)
        {
            arr[gap+1]=arr[gap];
            gap--;
        }
        arr[gap+1]=hold;
    }
}
int main()
{
    int arr[] = {1, 4, 3, 5, 2, 6, 8, 7};
    insertion_sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
}