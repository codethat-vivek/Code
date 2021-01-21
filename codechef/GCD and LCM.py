# Question Link - https://www.codechef.com/problems/FLOW016

# Solution Link - https://www.codechef.com/viewsolution/36701783

# SOLUTION - 

# cook your dish here

def gcd(a, b):
    while(b):
        a, b = b, a%b
    return a

def lcm(a, b):
    return a*b//gcd(a, b)

t = int(input())
for i in range(t):
    ab = list(map(int, input().strip().split()))
    a = ab[0]
    b = ab[1]
    print(gcd(a, b) ,end=" ")
    print(lcm(a, b))
