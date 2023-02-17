# Question Link - https://leetcode.com/problems/minimum-distance-between-bst-nodes/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        arr = []
        def inorder(root):
            if not root : return
            inorder(root.left)
            arr.append(root.val)
            inorder(root.right)
        
        inorder(root)
        ans = 10**10
        for i in range(1, len(arr)):
            ans = min(ans, arr[i]-arr[i-1])
        return ans
