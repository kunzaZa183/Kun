def letterRange(startLetter, endLetter):
    ans = "("
    while startLetter != endLetter:
        ans = ans + startLetter + ", "
        startLetter = str(chr(ord(startLetter[0]) + 1))
    ans = ans + startLetter + ")"
    return ans

start, end = input("Enter two characters: ").split()

print(letterRange(start, end))