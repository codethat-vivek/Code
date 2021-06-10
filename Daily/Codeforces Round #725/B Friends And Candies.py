# Question Link - https://codeforces.com/contest/1538/problem/B

# Solution - 

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    s = sum(l)
    if s%n != 0:
        print(-1)
    else:
        avg = s//n
        ans = 0
        for each in l:
            if each > avg:
                ans += 1
        print(ans)
