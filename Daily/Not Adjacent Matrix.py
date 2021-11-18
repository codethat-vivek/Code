# Question Link - https://codeforces.com/problemset/problem/1520/C

# Solution - 

def fun(n):
    if n == 1:
        print(1)
        return
    if n == 2:
        print(-1)
        return
    arr = [[0 for _ in range(n)]for i in range(n)]
    num = 1
    for j in range(n):
        a, b = 0, j
        while 0 <= a < n and 0 <= b < n:
            if num > n*n:
                num = 2
            arr[a][b] = num
            #i+1, j-1
            a += 1
            b -= 1
            num += 2
    for i in range(1, n):
        a, b = i, n-1
        while 0 <= a < n and 0 <= b < n:
            arr[a][b] = num
            a += 1
            b -= 1
            num += 2

        
    for i in range(n):
        for j in range(n):
            print(arr[i][j], end= " ")
        print()
    pass

def main():
    for _ in range(int(input())):
        n = int(input())
        fun(n)


main()
