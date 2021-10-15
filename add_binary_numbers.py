# PROGRAM TO ADD TWO BINARY NUMBERS

def decimal_to_binary(num):
    #this function recieves an integer and returns its binary equivalent
    rem=''
    while True:
        r=str(num%2)
        rem+=r
        num//=2
        if num==0:
            break
    rem=rem[::-1]
    return rem

def binary_to_decimal(num):
    #this function recieves a binary number and returns its decimal equivalent
    sums=0
    f=len(num)-1
    for i in num:
        sums+=int(i)*2**f
        f-=1
        if f<0:
            break
    return sums

def isbinary(num):
    '''this function helps validate if the binary number entered is valid i.e it
consists of only 0s and 1s'''
    for i in num:
        if int(i)>1:
            return False
    return True

def binary_adder(num1,num2):
    # the two numbers are first converted to decimal
    no1=binary_to_decimal(num1)
    no2=binary_to_decimal(num2)
    decimal_ans=no1+no2 #their decimal equivalent is then added
    bin_ans=decimal_to_binary(decimal_ans) #and the resulting answer is then converted back to binary form
    return bin_ans

while True: 
    bin_no_1=input('Enter binary number 1: ')
    bin_no_2=input('Enter binary number 2: ')
    if not isbinary(bin_no_1) or not isbinary(bin_no_2):
        #using the isbinary() function the numbers are verified to be binary
        print('Enter valid binary number!')
        continue
    break    
print(binary_adder(bin_no_1,bin_no_2))
