
list = [56, 65, 98, 2, 25]

# Keep track of the sum
total = 0

for num in list:
    # add item in list to total
    total += num

print("Sum of all numbers in myList is:",)
print(total )
      
total = 0

for x in range( len( list) ) :
    total += list[ x ]
print(total)
      
negsm = 0

for i in list:
    negsm += -i

print(negsm)

evens = 0

for i in list:
    if i % 2 == 1:
        evens += 1

print(evens)

divby7 = 0

for i in list:
    if i % 7 == 0:
        divby7 += 1

print(divby7)



