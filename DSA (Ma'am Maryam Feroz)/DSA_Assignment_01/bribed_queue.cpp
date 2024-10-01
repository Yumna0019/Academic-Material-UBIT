#include<iostream>      
#include<fstream>       
using namespace std;    

// Function to calculate the number of bribes in a queue
int BribedQueue(int arr[], int n)
{
    int hold, j, count = 0; // Initialize variables to hold values during sorting and count bribes

    for(int i = 0; i < n; i++) // Loop through the queue
    {
        hold = arr[i];    // Store the current person's original position
        j = i - 1;         // Initialize 'j' to the previous position in the queue

        while(j >= 0 && arr[j] > hold) // While there's a person ahead who bribed and pushed back
        {
            arr[j + 1] = arr[j]; // Move the person forward in the queue
            j--;
            count++; // Increment the count of bribes
        }
        arr[j + 1] = hold; // Place the person in the correct position after bribes
    }

    return count; // Return the total number of bribes
}

int main()
{
    int arr[100], n;    // Declare an array to represent the queue and a variable for its size
    string filePath;    // Declare a string variable to store the file path

    cout << "Enter the file path: "; // Prompt the user to enter the file path
    getline(cin, filePath);           // Read the file path from the user

    ifstream inputFile(filePath);     // Create an input file stream using the provided file path

    if (!inputFile)
    {
        cout << "Error opening the file." << endl; // Display an error message if the file cannot be opened
        return 1; // Exit the program with an error code
    }

    // Read the size of the queue from the file
    inputFile >> n;
    cout << "Size of array: " << n << endl; // Display the size of the queue

    // Read the queue elements from the file, assuming elements are separated by commas
    for (int i = 0; i < n; i++)
    {
        string element;
        getline(inputFile, element, ','); // Read an element from the file using a comma as the delimiter
        arr[i] = stoi(element);           // Convert the string element to an integer and store it in the array
    }

    inputFile.close(); // Close the input file

    cout << "You entered the following numbers: ";
    for(int i = 0; i < n ; i++) // Loop to print the queue
    {
        cout << arr[i];
        if(i != n - 1)
        {
            cout << ", "; // Print a comma if it's not the last element
        }
    }

    int counter = BribedQueue(arr, n); // Call the function to count the bribes

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << "\nNumber of bribes: " << counter << endl; // Display the number of bribes

    return 0; // Exit the program
}
