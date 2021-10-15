# Manish Bishowkarma
# 14 Oct, 2021
# Compute_pay.py


print("Paycheck Program\n")


def compute_pay():
    try:
        hrs = input("Please Enter Hours: ")
        h = float(hrs)
        rate = input("Please Enter Rate: $")
        r = float(rate)

    except:
        print("Please enter a numeric value!!!")
        quit()

    if h > 40:
        total_pay1 = 40 * r + (h - 40) * (r * 1.5)
        print("Total pay check due $", total_pay1)
    else:
        total_pay2 = r * h
        p = float(total_pay2)
        print("Total pay check due $", total_pay2)


compute_pay()
