string = input()
total = 0
allstring = ["one", "two" ,"three", "four", "five", "six", "seven", "eight","nine"]
while string != "Q":
    first = -1
    last = 0
    for i in range(len(string)):
        if string[i].isdigit():
            if first == -1:
                first = int(string[i])
            last = int(string[i])
        else:
            for num in allstring:
                if len(string) - i >= len(num):
                    if string[i:i + len(num)] == num:
                        if first == -1:
                            first = allstring.index(num) + 1
                        last = allstring.index(num) + 1
    total += first * 10 + last
    string = input()
print(total)