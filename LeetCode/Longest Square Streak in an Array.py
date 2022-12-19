# Question Link - https://leetcode.com/problems/longest-square-streak-in-an-array/

# Solution - 

class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        init = [True for _ in range(len(nums))]
        st = set(nums)
        for idx, each in enumerate(nums):
            x = math.sqrt(each)
            if x == int(x) and x in st:
                init[idx] = False
        
        #print(init)
        ans = -1
        
        for idx, each in enumerate(nums):
            if init[idx]:
                cnt = 1
                while each**2 in st:
                    cnt += 1
                    each = each**2
                if cnt >= 2:
                    ans = max(ans, cnt)
        
        return ans
