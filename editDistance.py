import numpy as np

def editDistance(s,t,n,m,dp):
    
    #if either of the strings is empty simply, return the length of the other one
    if(n==0): 
        return m
    if(m==0):
        return n
    
    #check matrix for optimal substructure
    if(dp[n][m]!=-1):
        return dp[n][m]
    
    if(s[n-1]==t[m-1]): #chars match
        return editDistance(s,t,n-1,m-1,dp)
    
    op1 = 1 + editDistance(s,t,n-1,m-1,dp) #substitution
    op2 = 1 + editDistance(s,t,n-1,m,dp) #insertion
    op3 = 1 + editDistance(s,t,n,m-1,dp) #deletion
    
    #Storing the minimum out of all the available options
    dp[n][m] = min(op1,op2,op3)
    return dp[n][m]
  

#Taking the inputs
s = input("Enter the 1st string ")
t = input("Enter the 2nd string ")

n = len(s)
m = len(t)

#Creating dp matrix to store the subproblems
dp = np.full((n+1,m+1), -1) 
    
ans = editDistance(s,t,n,m,dp)    
print("The edit distance is:",ans ) 
    