print("Logical Operators")

x = 50
y = 700
if x < 10 or y < 50:
    print("Fun")
elif x < 400 or y < 300:
    print("Wow")


x = 50
y = 100
if x < 400 and y < 300:
    print("Upper right")
elif x < 400 and y > 300:
    print("Upper left")
else:
    print("Bottom")

print("\nRelational Operators")
print("True or False")
print(True or False)

print("\nTrue and False")
print(True and False)

print("\nnot True")
print(not True)

side1 = 1
side2 = 2
side3 = 3
if(side1 + side2 > side3 or side1 + side3 > side2 or side2 + side3 > side1):
    print("It's a triangle")
else:
    print("It is not a triangle")

print("Not true and Not false")
print(not True and not False)

print("True or false")
print(True or False)