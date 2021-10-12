# Write a Python program to check if a string contains all unique characters
# Your Code here
from abc import abstractmethod


def isUniqueChars(str):

	
	if len(str) > 256:
		return False


	char_set = [False] * 128

	
	for i in range(0, len(str)):

	
		val = ord(str[i])
		if char_set[val]:
			return False

		char_set[val] = True

	return True


str = input("Enter Your String")
print(isUniqueChars(str))

