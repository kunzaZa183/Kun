def secondhalf(string:str):
    string = string.upper()
    ct = 0
    for i in string:
        if(i.isupper() and ord(i) >= ord("N")):
            ct += 1
    return ct
a = input("Enter string: ")
print("Number of characters that is N or after: " + str(secondhalf(a)))