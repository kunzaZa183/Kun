string = input()
total = 0
matches = []
while string != "Q":
    string = string.split()
    string.pop(0)
    string.pop(0)
    linein = 0
    for i in range(len(string)):
        if string[i] == "|":
            linein = i
            break
    arr1 = []
    arr2 = []
    for i in range(linein):
        arr1.append(string[i])
    for i in range(linein + 1, len(string)):
        arr2.append(string[i])
    ct = 0
    for i in arr1:
        if i in arr2:
            ct += 1
    matches.append(ct)
    string = input()
frequency = [1 for i in range(len(matches))]
for i in range(len(frequency)):
    for j in range(i + 1, min(len(frequency), i + matches[i] + 1)):
        frequency[j] += frequency[i]
print(sum(frequency))
