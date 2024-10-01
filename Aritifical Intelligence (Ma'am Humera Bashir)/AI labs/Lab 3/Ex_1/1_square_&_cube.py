# The list of integers
numbers = [1, 2, 3, 4, 5]

# Lambda functions for squaring and cubing
square = lambda x: x ** 2
cube = lambda x: x ** 3

squared_numbers = [square(num) for num in numbers]
cubed_numbers = [cube(num) for num in numbers]

# Print the squared and cubed numbers
print("Original Numbers:", numbers)
print("Squared Numbers:", squared_numbers)
print("Cubed Numbers:", cubed_numbers)
