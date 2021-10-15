def factorial(x):
    result = 1
    i = x
    while i <= x and i > 0:
        result *= i
        return result

while True:
    num1 = int(input("What is the first number? "))
    num2 = int(input("What is the second number? "))

    oper = input("Combination or permutation? ").lower()
    if oper == "combination":
        print(factorial(num1) / factorial(num2) * factorial(num1 - num2)
    elif oper == "permutation":
        print(factorial(num1) / factorial(num1 - num2)
    else:
        print("Invalid!")
        break
