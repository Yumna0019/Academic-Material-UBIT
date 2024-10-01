#include <iostream>
using namespace std;

void linear_search(int arr[], int size, int toSearch)
{
    bool flag;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == toSearch)
        {
            flag = true;
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    linear_search(arr, size, 9);
}