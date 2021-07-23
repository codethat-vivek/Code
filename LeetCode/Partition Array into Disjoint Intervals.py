# Question Link - 

# Solution - 

n = len(nums)
        if n == 2:
            return 1
        mx = [-1]*n
        mm = [-1]*n
        maxSoFar = -2
        minSoFar = 1000001
        
        for i in range(n):
            maxSoFar = max(maxSoFar, nums[i])
            mx[i] = maxSoFar
        for i in range(n-1, -1, -1):
            minSoFar = min(minSoFar, nums[i])
            mm[i] = minSoFar
        
        for i in range(n-1):
            if mx[i] <= mm[i+1]:
                return i+1
        return 1
