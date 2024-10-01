def int_to_roman(num):
    if not 0 <= num:
        return "Input the valid number"

    roman_numerals = {
        1000: 'M', 900: 'CM', 500: 'D', 400: 'CD',
        100: 'C', 90: 'XC', 50: 'L', 40: 'XL',
        10: 'X', 9: 'IX', 8: 'VIII', 7: 'VII', 6: 'VI' ,
        5: 'V', 4: 'IV', 3: 'III', 2: 'II' , 1: 'I'
    }

    result = ""
    for value, symbol in roman_numerals.items():
        while num >= value:
            result += symbol
            num -= value
    return result

number = int(input("Enter number: "))
roman_numeral = int_to_roman(number)
print(f"The Roman numeral representation of {number} is: {roman_numeral}")

