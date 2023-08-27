def convert(fah):
    return (fah - 32) * 5 / 9


fah = float(input("Enter temperature in Fahrenheit: "))
print(round(convert(fah),2),"degrees Celsius")
