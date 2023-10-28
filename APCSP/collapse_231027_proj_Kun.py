def collapse(lst:list):
    if len(lst) % 2 == 1:
        lst.append(0)
    newlst = []
    for i in range(0, len(lst), 2):
        newlst.append(lst[i] + lst[i+1])
    return newlst

something = list(map(int,input("Enter list: ").split()))

print(collapse(something))