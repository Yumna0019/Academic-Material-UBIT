import re
pattern=r'\b([+-]?([0-9]*)?[.][0-9]+([eE][+-]?[0-9]+)?)\b'

def match(text):
    if re.search(pattern,text):
        print("valid float number")
    else:
        print("invalid float number")


text=input("enter float number: ")

match(text)