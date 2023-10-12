num = input("Enter number = ")
if num == num[::-1]:
    print("{} is a Palindrome number.".format(num))
else:
    print("{} is not a Palindrome number.".format(num))