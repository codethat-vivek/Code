# Question Link - https://codeforces.com/problemset/problem/1517/A

# Solution - 

def fun(k):
    if k < 2050 : return -1
    if k % 2050 != 0 : return -1
    ans = 0
    t = str(k//2050)
    for each in t:
        ans += int(each)
    return ans


def main():
    t = int(input())
    for _ in range(t):
        k = int(input())
        print(fun(k))

main()

