#include<iostream>   
#include<fstream>    
using namespace std; 

// Function to search for a value in an array and print its index if found
void FixingTheCodeInProduction(int arr[], int n, int num)
{
    bool found = false; // Initialize a boolean variable to track whether the value is found

    // Loop through the array
    for(int i = 0; i < n; i++)
    {
        if(num == arr[i]) // Check if the current element matches the target value 'num'
        {
            cout << num << " Value Found at index: " << i << endl; // Print the index if found
            found = true; // Set the 'found' flag to true
            break; // Exit the loop once the value is found
        }   
    }

    if (!found)
    {
        cout << "Value not found (-1)" << endl; // If the value is not found, print a message
    }
}

int main()
{
    int arr[200], n, num; // Declare an array to store numbers, and variables for array size and the target value
    string filePath;      // Declare a string variable to store the file path

    cout << "Enter the file path: "; // Prompt the user to enter the file path
    getline(cin, filePath);           // Read the file path from the user
    
    ifstream inputFile(filePath);     // Create an input file stream using the provided file path

    if (!inputFile)
    {
        cout << "Failed to open the input file." << endl; // Display an error message if the file cannot be opened
        return 1; // Exit the program with an error code
    }
    
    inputFile >> num; // Read the number to search
    cout << "Search no. : " << num << endl;

    inputFile >> n; // Read the size of the array
    cout << "Size of array: " << n << endl;
    
    for (int i = 0; i < n; i++)
    {
        string element;
        getline(inputFile, element, ','); // Read an element from the file using a comma as the delimiter
        arr[i] = stoi(element);           // Convert the string element to an integer and store it in the array
    }
    
    inputFile.close(); // Close the input file
    
    cout << "You entered the following numbers: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i];
        if(i != n-1)
        {
            cout << ", "; // Print the comma if it's not the last element
        }
    }
    cout << endl;
    
    FixingTheCodeInProduction(arr, n, num); // Call the function to search for the target value

    return 0; // Exit the program 
}
