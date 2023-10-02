# Create an empty list
myList = []
print("Empty List")
print(myList)
print()

# Create a list with stuff in it
print("Lists with items in it")

aplus = [0,0,0,0,0,0,0,0,0,0]
print( aplus )


price = [32.23, 12.25, 56.38, 77.55, 39.0]
print(price)
print()

# print the original list
coworkers = ["Sarah", "Matt", "Sophie"]
print( coworkers )

# change the item at index 1 
coworkers[1] = "Tim"
print(coworkers)
print()

# Print the items in the list
print("Items at index 0 and 2")
print(coworkers[0], coworkers[2])
print()

print("1st price ",end = "")
print(price[0])

print("Last price = ",end = "")
print(price[-1])

print("Number of prices = ",end = "")
print(len(price))