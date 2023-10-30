# Question Link - https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

# Solution = 

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        import math
        maxBits = int(math.log(max(arr), 2)) + 1
        res = []
        for each in arr:
            num, cnt, t = 1, 0, maxBits
            while t:
                if (each&num) != 0:
                    cnt += 1
                t -= 1
                num <<= 1
            res.append((each, cnt))
        
        res.sort(key = lambda x : (x[1], x[0]))
        return [x for x, y in res]
        
        
