def count(num):
  ct = 0
  while num > 0:
    ct += num % 10
    num //= 10
  return ct

print(count(234))
print(count(10000))
print(count(111))
print(count(9005))
print(count(84645))
print()
print(count(8547))
print(count(123456789))
print(count(5555672468))
print(count(2548522125455))
print(count(2545588514548))
print()
print(count(111111111))
print(count(121212121212))