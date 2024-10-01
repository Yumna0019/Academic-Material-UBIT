# Prompt the user for a username
username = input("Enter your username: ")

# Prompt the user for a password
password = input("Enter your password: ")

# Known password values
valid_passwords = ["abc$123", "ABC$123"]

# Check if the lowercase version of the entered password is in the list of lowercase valid passwords
if password.lower() in [vp.lower() for vp in valid_passwords]:
    print("Welcome!")
else:
    print("I don't know you.")

