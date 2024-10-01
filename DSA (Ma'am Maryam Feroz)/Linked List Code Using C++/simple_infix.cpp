#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Define a function to convert infix to postfix notation.
string infixToPostfix(string infix) 
{
    // Initialize an empty string to store the resulting postfix expression.
    string postfix = " ";
    
    // Create a stack of characters to help with the conversion.
    stack<char> s;

    // Loop through each character in the input infix expression.
    for (char c : infix) 
    {
        // If the character is an alphabetic character (operand), add it to the postfix expression.
        if (isalpha(c)) 
        {
            postfix += c;
        }
        // If the character is the '+' operator, push it onto the stack.
        else if (c == '+') 
        {
            s.push(c);
        }
    }

    // After processing all characters, empty the stack and add its contents to the postfix expression.
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }

    // Return the resulting postfix expression.
    return postfix;
}

int main() 
{
    // Define an infix expression to be converted.
    string infix = "a+b";
    
    // Print the original infix expression.
    cout << "Infix expression: " << infix << endl;

    // Call the infixToPostfix function to convert the infix expression to postfix.
    string postfix = infixToPostfix(infix);
    
    // Print the resulting postfix expression.
    cout << "Postfix expression: " << postfix << endl;

    // Return 0 to indicate successful program execution.
    return 0;
}
