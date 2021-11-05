# Question Link - https://codeforces.com/problemset/problem/1607/D

# Solution - 

def fun():
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        colors = input()

        blue, red = [], []
        for i in range(n):
            if colors[i] == "B":
                blue.append(arr[i])
            else:
                red.append(arr[i])
        blue.sort()
        red.sort()
        
        flag = True
        for i in range(len(blue)):
            if blue[i] < i+1:
                flag = False
                break
        k = len(blue)
        for j in range(len(red)):
            if red[j] > k+1:
                flag = False
                break
            k += 1
        if flag:
            print("YES")
        else:
            print("NO")


fun()
