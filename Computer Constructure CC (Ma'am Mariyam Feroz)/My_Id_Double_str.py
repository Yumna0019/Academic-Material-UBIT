import re

# Identifier:  
# 1. Start with A.  
# 2. Middle Combo of A,D and -(hyphen).  
# 3. End with A,- and D.
identifier = r'^[a-zA-Z][a-zA-Z0-9-]*[a-zA-Z0-9]*$' 

# Double Type (DT)
double = r'\b[+-]?\d+(\.\d+([eE][+-]?\d+)?)?\b'

# String (str)
str = r'^\"(\\[ntrbof\\"\'\\]|\\"|\\\\|[^\\])*\"$'


def match(text):
    if re.fullmatch(identifier, text):
        print(f"{text}: valid identifier")
    elif re.fullmatch(double, text):
        print(f"{text}: valid double (DT)")
    elif re.fullmatch(str, text):
        print(f"{text}: valid string (str)")
    else:
        print(f"{text}: invalid")

# Test input
text = input("Enter identifier: ")
match(text)
