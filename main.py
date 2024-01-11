test = int(input())
for i in range(test):
    n = int(input())
    a = n * n * n - 6 * n * n + 11 * n - 6
    b = n * n - 3 * n + 2
    if b == 0:
        print("NO")
    else:
        print((a // b) % 1000000007)
