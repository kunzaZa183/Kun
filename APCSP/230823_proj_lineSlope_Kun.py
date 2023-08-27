def slope(x1, y1, x2, y2):
    return (y2 - y1) / (x2 - x1)


x1, y1 = map(int, input("Enter coordinates of first point: ").split())
x2, y2 = map(int, input("Enter coordinates of second point: ").split())
print("Slope is ::", round(slope(x1, y1, x2, y2), 2))
