import datetime
sample_datetime = datetime.datetime.now()

# A lambda function to extract year, month, date, hour, minute, and second
extract_components = lambda dt: (dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second)

# Call the lambda function with the datetime object
year, month, day, hour, minute, second = extract_components(sample_datetime)

print("Year:", year)
print("Month:", month)
print("Day:", day)
print("Hour:", hour)
print("Minute:", minute)
print("Second:", second)
