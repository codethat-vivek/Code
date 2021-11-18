# Question Link - https://codeforces.com/problemset/problem/1520/B

# Solution - 

def fun(n):
    ones = [1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111]
    ans = 0
    for i in range(len(ones)-1, -1, -1):
        if n < ones[i]:continue
        ans += min(9, n//ones[i])
    return ans

def main():
    for _ in range(int(input())):
        n = int(input())
        print(fun(n))

main()
