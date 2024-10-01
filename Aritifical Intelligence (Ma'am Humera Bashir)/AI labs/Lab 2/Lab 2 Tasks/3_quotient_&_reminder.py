def calculate_quotient_and_remainder(dividend, divisor):
    if divisor == 0:
        return "Error: Division by zero"

    quotient = 0
    remainder = dividend

    while remainder >= divisor:
        remainder -= divisor
        quotient += 1

    return quotient, remainder

# Get user input for dividend and divisor
dividend = int(input("Enter the dividend: "))
divisor = int(input("Enter the divisor: "))

# Calculate quotient and remainder
result = calculate_quotient_and_remainder(dividend, divisor)

# Display the result
print(f"Quotient: {result[0]}")
print(f"Remainder: {result[1]}")

