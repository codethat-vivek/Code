# Question Link - https://www.codechef.com/problems/CM164364

# SOLUTION - 

for _ in range(int(input())):
    n, x = map(int, input().split())
    l = list(map(int, input().split()))
    d = dict()
    possible = 0
    different = 0
    done = False
    for each in l:
        if each not in d:
            d[each] = 1
        else:
            d[each] += 1
    
    for key in d:
        different += 1;
        possible += (d[key] - 1)
    
    if possible >= x:
        print(different)
        done = True
    
    
    while different and not done:
        possible += 1
        different -= 1
        if possible >= x:
            print(different)
            done = True
            break
        
    
    if not done:
        print(-1)
