# Question Link - https://codeforces.com/problemset/problem/1520/A

# Solution - 

def fun(n, s):
    if n <= 2:
        return "YES"
    vis = [False for i in range(26)]
    prev = s[0]
    for each in s:
        idx = ord(each)-65
        if vis[idx] and prev != each:
            return "NO"
        vis[idx] = True
        prev = each
    return "YES"

def main():
    for _ in range(int(input())):
        n = int(input())
        s = input()
        print(fun(n, s))

main()
