
def hammingDistance(s,t):

    count = 0
    #iterating over both the strings and finding the count of unmatching characters
    for i in range(0,len(s)):
        if(s[i]!=t[i]):
            count+=1
            
    return count


s1 = input("Enter the first string ")
s2 = input("Enter the second string ")    

print("The hamming distance is ",hammingDistance(s1,s2))