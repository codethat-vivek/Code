# Question Link - https://codeforces.com/problemset/problem/1519/B

# Solution - 

def fun():
    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        if a*b-1 != c:
            print("NO")
        else:
            print("YES")
 
fun()
 
