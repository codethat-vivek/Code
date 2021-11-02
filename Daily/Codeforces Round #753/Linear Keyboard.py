# Question Link - https://codeforces.com/contest/1607/problem/A

# Solution - 

def fun():
    t = int(input())
    for _ in range(t):
        parent = input()
        sub = input()
        dt = dict()
        ans = 0
        for i in range(len(parent)):
            dt[parent[i]] = i
        for i in range(1, len(sub)):
            ans += abs(dt[sub[i]]-dt[sub[i-1]])
        print(ans)
fun()
