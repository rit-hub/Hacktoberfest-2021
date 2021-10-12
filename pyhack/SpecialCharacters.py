# Write a python program that will remove special characters from a string

# Your Code Here
import re

def find(string):
    special_char=re.compile('[@_!$%^&*()<>?/\|}{~:]#')
    
    if special_char.search(string) == None:
        return "string is accepted"
    else:
        return "string is not accpeted"
   

s="hi54dwd#"
print(s)
print(find(s))
