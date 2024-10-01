# Variables
shopping_cart = []  # List to store items in the shopping cart
discount_rate = 0.1  # 10% discount rate

# Functions
def add_item(item_name, item_price):
    """
    Function to add items to the shopping cart.
    """
    item = (item_name, item_price)
    shopping_cart.append(item)
    print(f"{item_name} added to the shopping cart.")

def calculate_total_cost():
    """
    Function to calculate the total cost of items in the shopping cart.
    """
    total_cost = sum(item[1] for item in shopping_cart)
    return total_cost

def apply_discount(total_cost):
    """
    Function to apply a discount to the total cost.
    """
    discounted_cost = total_cost - (total_cost * discount_rate)
    return discounted_cost

# Lists and Tuples
# Items in the shopping cart are represented as tuples (item_name, item_price)

# Conditional Statements
# If the total cost is above a certain threshold, apply a discount.
threshold_for_discount = 100

# User Input and Loop
while True:
    print("\n=== Shopping Cart ===")
    print("1. Add Item")
    print("2. View Cart")
    print("3. Checkout")
    print("4. Exit")

    choice = input("Enter your choice (1-4): ")

    if choice == '1':
        item_name = input("Enter item name: ")
        item_price = float(input("Enter item price: "))
        add_item(item_name, item_price)
    elif choice == '2':
        print("\n=== Cart Contents ===")
        for item_name, item_price in shopping_cart:
            print(f"{item_name}: ${item_price}")
        print("=====================")
    elif choice == '3':
        total_cost = calculate_total_cost()
        print(f"\nTotal Cost before discount: ${total_cost}")
        
        if total_cost > threshold_for_discount:
            discounted_cost = apply_discount(total_cost)
            print(f"Discount applied! Total Cost after discount: ${discounted_cost}")
        else:
            print("No discount applied.")
        
        print("Thank you for shopping! Checkout complete.")
        break
    elif choice == '4':
        print("Exiting the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 4.")

