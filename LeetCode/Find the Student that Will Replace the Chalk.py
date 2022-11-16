# Question Link - https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

# Solution - 

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        sm = sum(chalk)
        left = k % sm
        
        for i in range(1, len(chalk)):
            chalk[i] += chalk[i-1]
        
        r = bisect.bisect_left(chalk, left)
        #print(r, chalk)
        if chalk[r] == left:
            return r+1
        return r
