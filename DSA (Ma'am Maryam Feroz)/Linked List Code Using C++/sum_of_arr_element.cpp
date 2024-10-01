#include <iostream>

int main()
{
    int arr[10], sum = 0;
    std::cout << "Enter 10 array no.s: " << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "you enter following no.s: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        sum = sum + arr[i];
    }
    std::cout << "sum is : " << sum;
}