print("Multiplication Table:")
for i in range(9,10):
    for j in range(1, 11):
        print(f"{i} * {j} = {i * j}")
    print()

# Scenario 3: Output numbers 1 to 10 backwards
print("Numbers 1 to 10 backwards:")
for i in range(10,0,-1):
    print(i)

# Scenario 4: Loop for even numbers up to 10
print("Even numbers up to 10:")
for num in range(0, 11, 2):
    print(num)

# Scenario 5: Loop to sum numbers from 100 to 200
sum_numbers = 0
for num in range(100, 201):
    sum_numbers += num

print("Sum of numbers from 100 to 200:", sum_numbers)
