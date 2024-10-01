import re
pattern=r'\b(?:\d[ -]*?){13,16}\b'
def match(text):
    if re.fullmatch(pattern,text):
        print("valid debit/credit card number")
    else:
        print("invalid debit/credit card number")


text=input("enter your 13/16 digit debit/credit card number: ")

match(text)