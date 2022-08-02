# Question Link - https://leetcode.com/problems/binary-tree-paths/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root):
        if root == None:
            return []
        if root.left == None and root.right == None:
            return [str(root.val)]
        lp = self.helper(root.left)
        rp = self.helper(root.right)
        ans = []
        for each in lp:
            ans.append(str(root.val) + "->" + each)
        for each in rp:
            ans.append(str(root.val) + "->" + each)
        return ans
        
        
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        return self.helper(root)
