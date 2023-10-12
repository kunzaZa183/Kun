print("[",end = "")
for i in range(4):
    print("\"{}\"".format(chr(i + ord('A'))), end = "")
    if i != 3:
        print(", ", end = "")
print("]")

letters = ["apple", "ball", "car", "dog"]

print("[",end = "")
for i in letters:
    print("\"{}{}\"".format(i, i), end = "")
    if i != "dog":
        print(", ", end = "")
print("]")

print("[",end = "")
for i in range(4):
    print("(\"{}\", \"{}\")".format(letters[i], chr(i + ord('a'))), end = "")
    if i != 3:
        print(", ", end = "")
print("]")