# Question Link - https://leetcode.com/problems/delete-leaves-with-a-given-value/

# Solution - 

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if root is None:
            return None
        if root.val == target and root.left is None and root.right is None:
            # leaf node and I need to delete it 
            return None
        lp = self.removeLeafNodes(root.left, target)
        rp = self.removeLeafNodes(root.right, target)
        
        root.left = lp
        root.right = rp
        
        if root.val == target and root.left is None and root.right is None:
            return None
        
        return root
