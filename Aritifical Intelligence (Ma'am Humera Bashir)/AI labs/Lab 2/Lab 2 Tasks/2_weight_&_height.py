def calculate_bmi(weight_kg, height_m):
    # Calculate BMI using the formula: weight (kg) / (height (m) ^ 2)
    bmi = weight_kg / (height_m ** 2)
    return bmi

def classify_bmi(bmi):
    if bmi < 18.5:
        return "Underweight"
    elif 18.5 <= bmi < 24.9:
        return "Normal weight"
    elif 25.0 <= bmi < 29.9:
        return "Overweight"
    else:
        return "Obese"

# Get user input for weight and height
weight = float(input("Enter your weight in kilograms: "))
height = float(input("Enter your height in meters: "))

# Calculate BMI
user_bmi = calculate_bmi(weight, height)

# Classify BMI
classification = classify_bmi(user_bmi)

# Display the result
print(f"Your BMI is: {user_bmi:.2f}")
print(f"Classification: {classification}")

