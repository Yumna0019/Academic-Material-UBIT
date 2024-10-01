a = 2 ; b = 56 ; c = 78 ; d = 9
 
# Before swapping
print("Before swapping: a={}, b={}, c={}, d={}".format(a, b, c, d))

# Swapping values
temp = a
a = d
d = temp

temp = b
b = c
c = temp

# After swapping
print("After swapping: a={}, b={}, c={}, d={}".format(a, b, c, d))
