# Create an empty list
myList = []

# Add five random numbers between 10 and 50 to it
for num in range(5):
    myList.append(num)

print(myList)
print()


# Create a list
myList = [21,16,12,27,36]

print("Numbers in myList:")

myList = [56,65,98,2,25]

for num in myList:
    print(num)

sm = 0

for i in myList:
    sm += i

print(sm)

evens = 0

for i in myList:
    if i % 2 == 1:
        evens += 1

print(evens)

divby7 = 0

for i in myList:
    if i % 7 == 0:
        divby7 += 1

print(divby7)