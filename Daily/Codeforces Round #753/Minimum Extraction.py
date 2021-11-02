# Question Link - https://codeforces.com/contest/1607/problem/C

# Solution - 

def fun():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        if n == 1:
            print(arr[0])
            continue
        arr.sort()
        ans = arr[0]
        finalEffect = -arr[0]
        for i in range(1, n):
            ans = max(ans, arr[i]+finalEffect)
            finalEffect -= (arr[i]+finalEffect)
        print(ans)
        
 
    
fun()
