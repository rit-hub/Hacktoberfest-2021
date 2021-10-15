
#Finger Beam Pattern
rows=6;
for i in range(rows):
    for j in range(i):
        if i==1 and j==0:
          print(" ", end=" ")
        else:
            print("*",end=" ")

    if i<1:
     print(" ")

for i in range(1,rows):
    for j in range(rows, 1, -1):

        if j >i:
            print(" ", end=' ')
        if i==1:
            print("-", end=' ')
        else:
            print("*", end=' ')
    print("")