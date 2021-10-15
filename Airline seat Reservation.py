# Manish Bishowkarma
# 14 Oct, 2021
# Airline Seat Reservation


Reservation = {}
choice = None
while choice != "3":

    print(
        """ 
                Welcome to Mt.Everest Airline!

                        1 - Reserve seat
                        2 - Cancel a Reservation
                        3 - Exit program
    """
    )

    choice = input("Choice:")
    print()

    # Exit
    if choice == "3":
        print("Thank you for visit Mt.Everest Airline.")

    # Reserve seat
    elif choice == "1":

        row = int(input("Enter a Row(1-25):"))
        while row < 1 or row > 25:
            print("\nInvalid Row! please enter between 1 and 25.\n")
            row = int(input("Enter a Row(1-25):"))

        column = input("\nEnter a Coulmn(A-D):")
        while column == int() or column > "d":
            print("\nInvalid Column! please enter between A and D.\n")
            column = input("\nEnter a Coulmn(A-D):")
        seat = str(row) + column
        if seat not in Reservation:
            name = input("\nEnter your full name:")
            Reservation[seat] = name
            print(
                "\nSeat",
                seat.upper(),
                "has been successfully reserved for",
                name.capitalize(),
                ".",
            )
        else:
            print(
                "\nSorry!,Seat",
                seat.upper(),
                "already reserved for",
                Reservation[seat].capitalize(),
                ".",
            )

    # Canceled Reservation
    elif choice == "2":
        seat = input("Enter seat number :")
        cancel = "y"
        cancel = "n"
        if seat in Reservation:
            cancel = input(
                "\nCancel reservation for " + Reservation[seat].capitalize() + "(y/n)?:"
            )
            if cancel == "y":
                print(
                    "\nSeat",
                    seat.upper(),
                    "reservation for",
                    Reservation[seat].capitalize(),
                    "has been successfully canceled.",
                )
                del Reservation[seat]
            if cancel == "n":
                print("\nsorry! Invalid entery.")
        else:
            print("\nSorry! There is no reservation for seat", seat.upper(), ".")

    else:
        print("\nSorry!!! Invalid choice.")


input("Press enter key to exit.")
