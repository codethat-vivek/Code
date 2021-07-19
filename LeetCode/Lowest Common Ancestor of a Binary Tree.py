# Question Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, root, p, q):
        if root is None:
            return None
        if root == p or root == q:
            return root
        lp = self.helper(root.left, p, q)
        rp = self.helper(root.right, p, q)
        if lp != None and rp != None:
            return root
        if lp == None:
            return rp
        if rp == None:
            return lp
        return None
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.helper(root, p, q)
        
