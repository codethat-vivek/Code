# Question Link - https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def getHeight(node):
            if not node:
                return 0
            lh = getHeight(node.left)
            rh = getHeight(node.right)

            return max(lh, rh) + 1
        
        
        h = getHeight(root)

        def findLCA(node, ht):
            if not node:
                return None
            
            if ht < h:
                left = findLCA(node.left, ht+1)
                right = findLCA(node.right, ht+1)
                if left == None and right == None:
                    return None
                if left == None:
                    return right
                if right == None:
                    return left
                return node
            
            return node
        

        return findLCA(root, 1)
