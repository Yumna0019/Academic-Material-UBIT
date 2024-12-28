import re

# REs for integer and float constants
int_const = r'[+-]?\d+'
flt_const = r'[+-]?\d*\.\d+'

# REs for char & string 
A = r"(?:\\\\|\\'|\\\")"  
B = r"(?:\\[ntorb]|[a-zA-Z])"  
C = r"(?:[^\\'][@+])"  
D = r"[a-zA-Z\d]*"

# Combine the sets into the final pattern for character constants
char_const_pattern = f"'({A}|{B}|{C})'"
char_const = re.compile(char_const_pattern)

# Define the string constant pattern with double quotes
string_const_pattern = f'"({A}|{B}|{C}|{D})"'
string_const = re.compile(string_const_pattern)

# Test input
test_string = input("Enter the string: ")
words = test_string.split()

# Classification of each token 
for token in words:
    if re.fullmatch(int_const, token):
        print(f"{token}  : Int_Const")
    elif re.fullmatch(flt_const, token):
        print(f"{token}  : flt_Const")
    elif char_const.fullmatch(token):
        print(f"{token}  : char_const")
    elif string_const.fullmatch(token):
        print(f"{token}  : string_const")
    else:
        print(f"{token} does not belong to any defined class.")
