# Question Link - https://leetcode.com/problems/trim-a-binary-search-tree/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if root is None:
            return None
        lp = self.trimBST(root.left, low, high)
        rp = self.trimBST(root.right, low, high)
        if root.val < low:
            return rp
        if root.val > high:
            return lp
        root.left = lp
        root.right = rp
        return root
