# Question Link - https://leetcode.com/problems/diameter-of-binary-tree/

# Solution - 

class Solution:
    def helper(self, root):
        if root == None:
            return 0, 0
        lh, leftDiameter = self.helper(root.left)
        rh, rightDiameter = self.helper(root.right)
        h = max(lh, rh) + 1
        diameter = max(lh+rh, leftDiameter, rightDiameter)
        return h, diameter
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        h, d = self.helper(root)
        return d
        
