# Question Link - https://www.codechef.com/problems/LONGSEQ

# Solution - 

# cook your dish here
t = int(input())
for _ in range(t):
    k = input()
    s = 0
    for each in k:
        s += int(each)
    if s == len(k) - 1 or s == 1:
        print("Yes")
    else:
        print("No")
