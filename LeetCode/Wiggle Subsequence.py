# Question Link - https://leetcode.com/problems/wiggle-subsequence/

# Solution - 

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 1
        if(nums[0] < nums[1]):
            ans = 1
            flow = "inc"
            for i in range(len(nums)-1):
                if flow == "inc" and nums[i] < nums[i+1]:
                    ans += 1
                    flow = "dec"
                elif flow == "dec" and nums[i] > nums[i+1]:
                    ans += 1
                    flow = "inc"
            return ans
        elif(nums[0] > nums[1]):
            ans = 1
            flow = "dec"
            for i in range(len(nums)-1):
                if flow == "dec" and nums[i] > nums[i+1]:
                    ans += 1
                    flow = "inc"
                elif flow == "inc" and nums[i] < nums[i+1]:
                    ans += 1
                    flow = "dec"
            return ans
        else:
            i = 0
            n = len(nums)
            while i+1 < n and nums[i] == nums[i+1]:
                i+=1
            if i+1 == n:
                return 1
            else:
                return self.wiggleMaxLength(nums[i:])
                
