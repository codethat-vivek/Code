# Question Link - https://codeforces.com/problemset/problem/1521/A

# Solution - 

def fun(a, b):
    if b == 1:
        print("NO")
        return
    print("YES")
    print(a, a*b, a*(b+1))
    

def main():
    for _ in range(int(input())):
        a, b = map(int, input().split())
        fun(a, b)


main()
