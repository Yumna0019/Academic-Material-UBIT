# Open the file in append mode
file = open("city_data.txt", "a")

# Prompt the user for the number of cities
num_cities = int(input("Enter the number of cities: "))

# Loop to accept data for each city
for i in range(num_cities):
    city_name = input("Enter the name of the city: ")
    population = input("Enter the population of the city: ")
    mayor = input("Enter the name of the mayor: ")

    # Write the city data to the file
    file.write(f"{city_name},{population},{mayor}\n")

print("City data has been successfully stored.")

# Close the file
file.close()
