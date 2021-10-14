
import random


# Manish Bishowkarma
# 14 Oct, 2021
# Powerball.py

# generating the powerball lottery numbers
choice = "y"
while choice !="n":
    print("\n\t\t\tPowerball Game!\n\n")
    numbers = []    
    for i in range(1,6): 
        num = int(input("Enter number #" + str(i) +": "))
        while num in numbers:
            print("The numbers must be unique, try again.")
            num = int(input("Enter number #" + str(i) +": "))
        while num < 1 or num > 69:
            print("The number must be between 1 and 69, try again.")
            num = int(input("Enter number #" + str(i) +": "))
        numbers.append(num)
    numbers.sort()     
    for i in range(1):
        powerball = int(input("\nEnter Powerball #:"))
        while powerball < 1 or powerball > 26:
            print("The number must be between 1 and 26, try again.")
            powerball = int(input("\nEnter Powerball #:"))
        

    print("\nYour numbers were:")
    for num in numbers:
        print(num,end=" ")
    print(powerball)
    print()

    # computer generate random powerball lottery numbers
    drawing = []
    com_num = random.randint(1,69)
    for i in range(1,6):
       
        
        while drawing.count(com_num) >= 1:
            com_num = random.randint(1,69)
        
        drawing.append(com_num)
    drawing.sort()
            
    for i in range(1):
        com_powerball= random.randint(1,26)
        

        print("\n\nWinning numbers are:")
        for com_num in drawing:
            print(com_num,end=" ")
        print(com_powerball)
    print()


    #matching numbers and for prize.

    match = 0
    match_1=0
    for num  in numbers:
        for com_num in  drawing:
            if num == com_num:
                match+=1
                
    
    
    if match == 1 and powerball == com_powerball:
        print("you matched 1 number and powerball.")
        print("you win $2.00")
        
    if match == 1 and powerball != com_powerball:
        print("you matched 1 number.")
        print("you win $1.00")

    if match == 2 and powerball == com_powerball:
        print("you matched 2 number and powerball.")
        print("you win $20.00")


    if match == 2 and powerball != com_powerball:    
        
        print("you matched 2 number.")
        print("you win $10.00")

        
    if match == 3 and powerball == com_powerball:
        print("you matched 2 number and powerball.")
        print("you win $20.00")

    if match == 3 and powerball != com_powerball:    
       
        print("you matched 3 number.")
        print("you win $100.00")

    if match == 0 and powerball == com_powerball:
        print("you matched powerball only.you win $3.00")

    if match == 0 and powerball != com_powerball:    
        print("you didn't win. sorry")

        
   

            
    choice = input("\nDo you want to play again?(y/n):")       
    if choice == "n":
        print("\nThank you for playing.Good-Bye")
        break
    
    
input("\nPress enter to exit.")  


    

