def payment(salary, hours):
  if hours >= 8:
    return salary * 8 + salary * 1.5 * (hours - 8)
  return salary * hours

salary = float(input("Enter salary: "))
hours = float(input("Enter hours: "))

print(payment(salary,hours))