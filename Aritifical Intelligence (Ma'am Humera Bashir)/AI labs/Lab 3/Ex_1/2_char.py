# Take input from the user for the string
given_string = input("Please enter a string: ")

# Take input from the user for the character
given_character = input("Please enter a character: ")

# Lambda function to check if the given string starts with the given character
starts_with_char = lambda string, char: string.startswith(char)

# Call the lambda function to check if the given string starts with the given character
result = starts_with_char(given_string, given_character)

# Print the result
print("Does the string start with the given character?", result)
