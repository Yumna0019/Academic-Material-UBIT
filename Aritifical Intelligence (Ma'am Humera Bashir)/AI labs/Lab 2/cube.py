def calculate_volume(height, width, depth):
    return height * width * depth

def get_volume_label(volume):
    if 1 <= volume <= 10:
        return "Extra Small"
    elif 11 <= volume <= 25:
        return "Small"
    elif 26 <= volume <= 75:
        return "Medium"
    elif 76 <= volume <= 100:
        return "Large"
    elif 101 <= volume <= 250:
        return "Extra Large"
    elif volume >= 251:
        return "Extra-Extra Large"

def main():
    # Taking user inputs for height, width, and depth
    height = float(input("Enter the height of the cube: "))
    width = float(input("Enter the width of the cube: "))
    depth = float(input("Enter the depth of the cube: "))

    # Calculating the volume of the cube
    volume = calculate_volume(height, width, depth)

    # Getting the volume label based on the calculated volume
    label = get_volume_label(volume)

    # Printing the result
    print(f"\nVolume of the cube: {volume} cm3")
    print("Label:", label)

if __name__ == "__main__":
    main()

