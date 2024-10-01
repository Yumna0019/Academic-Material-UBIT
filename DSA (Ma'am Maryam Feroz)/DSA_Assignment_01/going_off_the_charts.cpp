#include <iostream>      
#include <fstream>       
using namespace std;    

// Function to find the maximum consecutive days of working hours above 6
int GoingOffTheCharts(int arr[], int n)
{
    int max_con_days = 0; // Initialize a variable to store the maximum consecutive days
    int con_days = 0;     // Initialize a variable to count consecutive days

    // Loop through the array of working hours
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 6)   // Check if the working hours for the current day are above 6
        {
            con_days++;   // Increment the consecutive days count
        }
        else
        {
            con_days = 0; // Reset the consecutive days count if the working hours are not above 6
        }

        max_con_days = max(max_con_days, con_days); // Update the maximum consecutive days
    }

    return max_con_days; // Return the maximum consecutive days
}

int main()
{
    int arr[50], n;     // Declare an array to store working hours and a variable for array size
    string filePath;    // Declare a string variable to store the file path

    cout << "Enter the file path: "; // Prompt the user to enter the file path
    getline(cin, filePath);           // Read the file path from the user

    ifstream inputFile(filePath);      // Create an input file stream using the provided file path
    if (!inputFile)                    // Check if the file could not be opened
    {
        cout << "Error opening the file." << endl; // Display an error message
        return 1;                     // Exit the program with an error code
    }

    inputFile >> n;        // Read the size of the array from the file
    cout << "Size of array: " << n << endl; // Display the size of the array

    // Read the array elements from the file, assuming elements are separated by commas
    for (int i = 0; i < n; i++)
    {
        string element;                // Declare a string variable to temporarily store each element
        getline(inputFile, element, ','); // Read an element from the file using a comma as the delimiter
        arr[i] = stoi(element);        // Convert the string element to an integer and store it in the array
    }
    inputFile.close();                 // Close the input file stream

    cout << "You entered the following working hours: ";
    for (int i = 0; i < n; i++)  // Loop to print the array
    {
        cout << arr[i];         // Print the current element
        if (i != n - 1)
        {
            cout << ", ";      // Print a comma if it's not the last element
        }
    }

    int ConsecutiveDays = GoingOffTheCharts(arr, n); // Call the function to find maximum consecutive days
    {
        cout << endl;               // Move to the next line for clarity
        cout << "Maximum Consecutive Days with working hours above 6: " << ConsecutiveDays; // Display the result
    }

    return 0; // Exit the program 
}
