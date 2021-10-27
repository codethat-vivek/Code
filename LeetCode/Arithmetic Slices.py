# Question Link - https://leetcode.com/problems/arithmetic-slices/

# Solution - 

class Solution:
    def calc(self, k):
        return (k-2)*(k-1)//2
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3 : return 0
        i, j = 0, 1
        d = nums[1]-nums[0]
        ans = 0
        while j < n:
            if nums[j] - nums[j-1] == d:
                j+=1
            else:
                ans += self.calc(j-i)
                i = j-1
                d = nums[j]-nums[j-1]
                j += 1
        ans += self.calc(j-i)
        return ans
