# Question Link - https://www.codechef.com/problems/PALL01 

# Solution Link - https://www.codechef.com/viewsolution/36490031

# SOLUTION - 

t = int(input())
for i in range(t):
    k = input()
    temp = k[::-1]
    if k == temp:
        print("wins")
    else:
        print("loses")
    
