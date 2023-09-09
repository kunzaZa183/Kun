a = float(input("Give me a: "))
b = float(input("Give me b: "))
c = float(input("Give me c: "))


print("First root is",(-b + (b * b - 4 * a * c) ** (1/2)) / 2 / a, "\nSecond root is", (-b - (b * b - 4 * a * c) ** (1/2)) / 2 / a)