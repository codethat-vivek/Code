# Question Link - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        # O(n)
        ans = 0
        def dfs(root):
            if not root : return (inf, -1)
            if not root.left and not root.right : return (root.val, root.val)
            lmn, lmx = dfs(root.left)
            rmn, rmx = dfs(root.right)
            nonlocal ans
            ans = max(ans, abs(root.val - max(lmx, rmx)), abs(root.val - min(lmn, rmn)))
            return (min(root.val, lmn, rmn), max(root.val, lmx, rmx))
        
        
        dfs(root)
        
        return ans
