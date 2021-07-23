# Question Link - https://leetcode.com/problems/binary-tree-pruning/

# Solution - 

class Solution:
    def helper(self, root):
        if root is None:
            return None
        root.left = self.helper(root.left)
        root.right = self.helper(root.right)
        
        if root.val == 0 and root.left == None and root.right == None:
            return None
        return root
        
    def pruneTree(self, root: TreeNode) -> TreeNode:
        return self.helper(root)
