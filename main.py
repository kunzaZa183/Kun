import math

num = 1
for i in range(1, 1069):
    num *= i
print(math.log10(num))

num2 = 1
for i in range(500):
    num2 *= 350001
print(math.log10(num2))