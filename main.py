def fact(num):
    ans = 1
    for i in range(1,num+1):
        ans *= i
    return ans
print(fact(5))
print(fact(100)/fact(85)/fact(15) * (0.11 ** 15) * (0.89 **85))