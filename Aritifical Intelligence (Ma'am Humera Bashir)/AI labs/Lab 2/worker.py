# Taking user input for time taken by the worker
time_taken_str = input("Enter the time taken by the worker in hours: ")
time_taken = float(time_taken_str)

# Determine efficiency based on the time taken
if 2 <= time_taken <= 3:
    efficiency = "Highly Efficient"
elif 3 < time_taken <= 4:
    efficiency = "Improve Speed"
elif 4 < time_taken <= 5:
    efficiency = "Training Required"
elif time_taken > 5:
    efficiency = "Time to Leave"
else:
    efficiency = "Invalid input. Please enter a valid numerical value for time."

# Print the result
print(f"Efficiency of the worker: {efficiency}")

