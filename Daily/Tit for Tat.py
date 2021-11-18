# Question Link - https://codeforces.com/problemset/problem/1516/A

# Solution - 

def fun():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        i, j = 0, n-1
        while i != j and k != 0:
            while i < len(arr) and arr[i] == 0:
                i += 1
            if i >= len(arr)-1:
                break
            arr[i] -= 1
            arr[j] += 1
            k -= 1
            
        for each in arr:
            print(each, end=" ")
        print()
        pass



fun()
