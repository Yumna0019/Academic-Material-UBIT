#include <iostream>
using namespace std;

void binary_search(int arr[], int size, int toSearch)
{
    bool flag = false;
    int l = 0;
    int u = size - 1;
    while (l <= u)
    {
        int mid = (l + u)/ 2; 
        if (arr[mid] == toSearch)
        {
            flag = true;
            break;
        }
        else if (arr[mid] < toSearch)
        {
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
    }
    if (flag)
    {
        cout << "The value is found" << endl;
    }
    else
    {
        cout << "The value is not found" << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    binary_search(arr, size, 78); 
    
    return 0;
}