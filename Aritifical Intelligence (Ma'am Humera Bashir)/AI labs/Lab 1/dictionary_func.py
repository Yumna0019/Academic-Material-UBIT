# Create an empty dictionary for demonstration
my_dict = {}

# Use dir() to list available functions and methods
print("Available functions and methods for dictionaries:")
print(dir(my_dict))

# Use help() to get information about a specific function or method
print("\nHelp on dict.update method:")
help(my_dict.update)

# Demonstrate a few dictionary operations
my_dict.update({1: 'apple', 2: 'banana'})
print("\nUpdated Dictionary:", my_dict)

# Adding a new key-value pair
my_dict[3] = 'cherry'
print("After Adding a New Key-Value Pair:", my_dict)

# Removing a key-value pair
my_dict.pop(2)
print("After Removing Key 2:", my_dict)

