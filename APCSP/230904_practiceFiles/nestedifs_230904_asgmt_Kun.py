print("Nested ifs example")
grade = 97
if grade >= 70:
    print("Passing")
    if grade >= 90:
        print("A")
    elif grade >= 80:
        print("B")
    elif grade >= 75:
        print("C")
    else:
        print("D")
else:
    print("Failing")

age = 70
if age > 40:
    print("Old")
    if age > 50:
        print("Very Old")
    elif age > 60:
        print("Super Old")
else:
    print("Young")

height = 180
if height >= 180:
    print("Tall")
    if height >= 190:
        print("Super Tall")
    elif height >= 200:
        print("Way too tall")
else:
    print("Short")

aps = 15
if aps >= 10:
    print("Decent")
    if aps >= 15:
        print("Good")
    elif aps >= 20:
        print("Ok")
else:
    print("Failure")
