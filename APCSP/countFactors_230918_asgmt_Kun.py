def countFactors(num):
    # O (n)
    counter = 0
    for i in range(1, num + 1):
        if num % i == 0:
            counter += 1
    print("Number of factors =", counter)
    for i in range(1, num + 1):
        if num % i == 0:
            print(i, end=" ")
    print("\n")

countFactors(20)
countFactors(24)
countFactors(67)
countFactors(820)