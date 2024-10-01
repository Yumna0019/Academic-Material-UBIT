#regex for cnic:
import re
pattern= r'\b[1-7]([1-9]|[1-3][0-9])(?:[1-9]|[1-9][0-9]|1[0-6][0-9]|170)(?:[0-9]|[1-9][0-9]|[1-2][0-9]{2}|3[0-5][0-9]|360)(?:[1-9]|[1-9][0-9]{1,2}|[1-6][0-9]{3}|7[0-8][0-9]{2}|7979)[-]*[0-9]{7}[-]*[0-9]\b'

def match(text):
    if re.search(pattern,text):
        print("valid cnic number")
    else:
        print("invalid cnic number")


text=input("enter cnic: ")

match(text)