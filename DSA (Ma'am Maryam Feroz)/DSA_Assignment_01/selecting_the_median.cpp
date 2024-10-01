#include<iostream>           
#include<fstream>             
using namespace std;          

// Function to find the median of an array
int SelectingTheMedian(int arr[], int n)
{
    int hold, j, median;      // Declare variables to hold values during sorting and to store the median

    // Sort the array using insertion sort
    for(int i=0; i<n; i++)    // Loop through the array
    {
        hold = arr[i];        // Store the current element in the 'hold' variable
        j = i - 1;            // Initialize 'j' to the previous index

        // Shift elements of arr[0..i-1] that are greater than hold
        while(j >= 0 && arr[j] > hold) // Continue until you find the correct spot for 'hold'
        {
            arr[j+1] = arr[j]; // Shift the larger element to the right
            j--;              // Move to the previous index
        }
        arr[j+1] = hold;      // Place 'hold' in its correct sorted position
    }

    // Calculate the median based on array length
    if (n % 2 == 1)
    {
        // If the length is odd
        median = arr[n / 2]; // Median is the middle element
    }
    else
    {
        // If the length is even, calculate the average of the middle two elements
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }

    return median;           // Return the calculated median
}

int main()
{
    int arr[1005], n;          // Declare an array to store numbers and a variable for array size
    string filePath;           // Declare a string variable to store the file path

    cout << "Enter the file path: "; // Prompt the user to enter the file path
    getline(cin, filePath);           // Read the file path from the user

    ifstream inputFile(filePath);     // Create an input file stream using the provided file path

    // Check if the file opened successfully
    if (!inputFile)
    {
        cout << "Error opening the file." << endl; // Display an error message
        return 1;                                  // Exit the program with an error code
    }

    // Read the size of the array from the file
    inputFile >> n;
    cout << "Size of array: " << n << endl; // Display the size of the array

    // Read the array elements from the file, assuming elements are separated by commas
    for (int i = 0; i < n; i++)
    {
        string element;
        getline(inputFile, element, ','); // Read an element from the file using a comma as the delimiter
        arr[i] = stoi(element);           // Convert the string element to an integer and store it in the array
    }

    inputFile.close();                      // Close the input file stream

    cout << "You entered the following numbers: ";
    for (int i = 0; i < n; i++)             // Loop to print the array
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";                  // Print a comma if it's not the last element
        }
    }

    // Find and print the median
    int median = SelectingTheMedian(arr, n);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << "\nMedian: " << median << endl;

    return 0; // Exit the program 
}
