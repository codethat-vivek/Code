# Question Link - https://leetcode.com/problems/maximum-binary-tree/

# Solution - 

class Solution:
    def indexOfMax(self, nums):
        t = max(nums)
        return [t, nums.index(t)]
    
    def helper(self, nums):
        mx, idx = self.indexOfMax(nums)
        leftpart = nums[:idx]
        rightpart = nums[idx+1:]
        root = TreeNode(mx)
        if leftpart != []:
            root.left = self.constructMaximumBinaryTree(leftpart)
        if rightpart != []:
            root.right = self.constructMaximumBinaryTree(rightpart)
        return root
        
        
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        return self.helper(nums)
