# Question Link - https://www.codechef.com/problems/PRB01

# Solution Link - https://www.codechef.com/viewsolution/36496187

# SOLUTION - 

def isPrime(n):
    import math as m
    if n == 2:
        return "yes"
    if n == 1:
        return "no"
    for j in range(2, int(m.sqrt(n))+1, 1):
        if n%j == 0:
            return "no"
    return "yes"

t = int(input())
for i in range(t):
    n = int(input())
    print(isPrime(n))
