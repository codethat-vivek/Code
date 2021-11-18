# Question Link - https://codeforces.com/problemset/problem/1519/A

# Solution - 

def fun():
    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        if c == 0:
            if a == b:
                print("YES")
            else:
                print("NO")
            continue
        bags = 0
        if abs(b-a)%c == 0:
            bags = abs(b-a)//c
        else:
            bags = abs(b-a)//c + 1
        if bags > min(a ,b):
            print("NO")
        else:
            print("YES")


fun()
 
