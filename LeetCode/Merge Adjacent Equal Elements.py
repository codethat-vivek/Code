# Question Link - https://leetcode.com/problems/merge-adjacent-equal-elements/description/

# Solution - 

class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        stack = []
        n = len(nums)

        for i in range(n):
            stack.append(nums[i])
            while len(stack) > 1 and stack[-1] == stack[-2]:
                stack[-2] = 2*stack[-2]
                stack.pop()
            
        
        return stack
