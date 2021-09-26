# Question Link - https://leetcode.com/problems/product-of-array-except-self/

# Solution - 

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # O(n) time and O(1) space
        n = len(nums)
        ans = [1 for _ in range(n)]
        for i in range(1, n):
            ans[i] = ans[i-1]*nums[i-1]
        p = 1
        for i in range(n-2, -1, -1):
            p = p * nums[i+1]
            ans[i] *= p;
        return ans
