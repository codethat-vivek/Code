# Question Link - https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

# Solution - 

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        dt = collections.Counter(nums)
        n = len(nums)
        
        ans = []
        while len(dt) > 0:
            t = []
            for key in dt:
                if dt[key] != 0:
                    t.append(key)
                    dt[key] -= 1
            if len(t) == 0:
                break
            ans.append(t)
        
        return ans
