def repl(string, times):
    if times <= 0:
        return ""
    ans = ""
    for i in range(times):
        ans += string + " "
    return ans

string = input("Enter string:\n")
times = int(input("Enter times: "))
print(repl(string, times)) 