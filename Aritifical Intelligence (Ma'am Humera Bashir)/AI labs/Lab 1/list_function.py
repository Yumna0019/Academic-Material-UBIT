# def count_strings_with_same_ends(strings_list):
#     count = 0
#     for string in strings_list:
#         if len(string) >= 2 and string[0] == string[-1]:
#             count += 1
#     return count


# list = ["yummy","hye","yes","wow","xyz","txt"]

# # Call the function to count strings with the specified conditions
# result = count_strings_with_same_ends(list)

# # Display the result
# print("Number of strings with length 2 or more and same first and last character: {}".format(result))

# def generate_lowercased_strings(strings_list):
#     return [string.lower() for string in strings_list if len(string) > 5]

# strings_list = ["HELLO", "WORLD", "PYTHON", "LIST", "COMPREHENSION"]

# # Call the function to generate lowercased strings with length greater than 5
# result = generate_lowercased_strings(strings_list)

# # Display the result
# print("Lowercased strings with length greater than 5: {}".format(result))


# Sample list
list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Remove 0th, 4th, and 5th elements
indices_to_remove = [0, 4, 5]
modified_list = [element for index, element in enumerate(list) if index not in indices_to_remove]

# Display the modified list
print("Original List:", list)
print("Modified List after removing elements at indices 0, 4, and 5:", modified_list)

