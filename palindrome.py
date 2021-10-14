def isPalindrome(s):
    return s == s[::-1]


s = input("Enter a string: ")

if isPalindrome(s):
    print(f"{s} is a palindrome")
else:
    print(f"{s} is not a palindrome")
