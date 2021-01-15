# Question Link - https://www.codechef.com/problems/CIELRCPT

# Solution Link - https://www.codechef.com/viewsolution/36496373

# SOLUTION - 

t = int(input())
for i in range(t):
    n = int(input())
    l=[2048,1024,512,256,128,64,32,16,8,4,2,1]
    cnt = 0
    for j in l:
        if n >= j:
            cnt += n//j
            n %= j
    print(cnt)
