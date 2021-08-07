# Question Link - https://leetcode.com/problems/validate-binary-search-tree/

# Solution - 

class Solution:
    
    def helper(self, root, minn, maxx):
        if root is None:
            return True
        if root.val < minn or root.val > maxx:
            return False
        return self.helper(root.left, minn, root.val-1) and self.helper(root.right, root.val+1, maxx)
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        minn = -2147483650
        maxx = 2147483650
        return self.helper(root, minn, maxx)
