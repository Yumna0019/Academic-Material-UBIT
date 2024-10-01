print("\nCountries in clist:")
clist = ["Canada", "USA", "Mexico"]
index = 0
while index < len(clist):
    print(clist[index])
    index += 1


print("\nSum numbers in a while loop:")
total = 0
number = 1
while number <= 10:
    total += number
    number += 1
print("Sum of numbers from 1 to 10:", total)


# Example: Using a for loop inside a while loop
count = 0
while count < 3:
    print(f"\nCount: {count}")
    for i in range(2):
        print(f"  Inner loop iteration: {i}")
    count += 1
