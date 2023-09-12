a = ""
arr = []
while a != "DONE":
  a = input()
  arr.append(a)
arr.pop()
for string in arr:
  print("print(count({}))".format(string))
