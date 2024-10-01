#include <iostream>

struct stack
{
    char c;
    stack *next;
};
struct stack *start = NULL; // Initialize a stack and set the starting pointer to NULL

bool check_char(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return true; // Check if the character is a lowercase or uppercase letter and return true if so
    }
    return false; // Otherwise, return false
}

int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 5; // Set precedence to 5 for multiplication and division
    }
    else if (c == '+' || c == '-')
    {
        return 4; // Set precedence to 4 for addition and subtraction
    }
    else if (c == '>' || c == '<')
    {
        return 3; // Set precedence to 3 for greater-than and less-than operators
    }
    else if (c == '&')
    {
        return 2; // Set precedence to 2 for the bitwise AND operator
    }
    else
    {
        return 1; // Set precedence to 1 for other characters
    }
}

void push(char c1)
{
    struct stack *temp = new stack(); // Create a new stack node
    temp->c = c1;                     // Set its character value
    temp->next = NULL;                // Initialize the next pointer to NULL

    if (start == NULL)
    {
        start = temp; // If the stack is empty, set 'start' to the new node
    }
    else
    {
        temp->next = start; // Otherwise, link the new node to the current 'start'
        start = temp;       // Update 'start' to the new node
    }
}

struct stack *pop()
{
    if (start != NULL)
    {
        struct stack *curr = start; // Store the current 'start'
        start = start->next;        // Move 'start' to the next node
        delete curr;                // Delete the previous 'start'
    }
    return start; // Return the updated 'start'
}

std::string postfix(std::string equation)
{
    std::string eqn; // Initialize an empty string to store the postfix expression

    for (int i = 0; i < equation.length(); i++)
    {
        if (check_char(equation[i]))
        {
            eqn = eqn + equation[i]; // Append letters to the postfix expression
        }
        else if (equation[i] == '(')
        {
            push(equation[i]); // Push an open parenthesis onto the stack
        }
        else if (equation[i] == ')')
        {
            while (start != NULL && start->c != '(')
            {
                eqn += start->c; // Append operators from the stack until an open parenthesis is encountered
                pop();           // Pop the open parenthesis
            }
            if (start != NULL)
            {
                pop(); // Pop the open parenthesis
            }
        }
        else
        {
            if (equation[i] == '&' || equation[i] == '|' || equation[i] == '!')
            {
                i++; // Handle special characters like '&&', '||', and '!'
            }
            while (start != NULL && precedence(equation[i]) <= precedence(start->c))
            {
                eqn += start->c; // Append operators from the stack with higher or equal precedence
                pop();           // Pop the operators
            }
            push(equation[i]); // Push the current operator onto the stack
        }
    }

    while (start != NULL)
    {
        eqn += start->c; // Append any remaining operators from the stack
        pop();           // Pop the remaining operators
    }

    return eqn; // Return the final postfix expression
}

int main()
{
    std::string str;
    std::cout << "Enter the equation: " << std::endl;
    std::getline(std::cin, str);            // Read the input expression with spaces
    std::string postfix_eqn = postfix(str); // Call the postfix function to convert the expression

    // Print the final postfix expression
    std::cout << "Postfix expression: " << postfix_eqn << std::endl;
}
