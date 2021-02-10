# Question Link - https://www.codechef.com/problems/TWTCLOSE

# Solution Link - https://www.codechef.com/viewsolution/36746848

# SOLUTION - 

# cook your dish here
n,k = map(int,input().split())
arr = [0]*n

for i in range(k):
    tweet = input()
    if tweet == 'CLOSEALL':
        arr = [0]*n
    else:
        tweet = tweet.split()
        arr[int(tweet[1]) - 1] = 1 if arr[int(tweet[1]) - 1] == 0 else 0
        
    print(sum(arr))
