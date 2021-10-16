# Fast Algorithm to generate prime numbers in log(n), Sieve of Eratosthenes


def SieveOfEratosthenes(n):
    primes = [True for i in range(0, n + 1)]  # making a boolean array to store ans
    i = 2  # iterating from lowest prime number
    while i * i <= n:
        if primes[i]:
            j = i * i
            while j <= n:  # setting its multiples as false
                primes[j] = False
                j = j + i
        i = i + 1

    for i in range(2, n + 1):
        if primes[i]:
            print(i)


# for taking input
n = int(input())
# function call
SieveOfEratosthenes(n)
