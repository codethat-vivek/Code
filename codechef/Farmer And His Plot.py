# Question Link - https://www.codechef.com/problems/RECTSQ

# Solution - 

# cook your dish here
def gcd(x, y):
    while y:
        x, y = y, x%y
    return x
    
    
t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    hcf = gcd(x, y)
    print(x*y//(hcf**2))
