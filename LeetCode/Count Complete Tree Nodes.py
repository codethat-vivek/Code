# Question Link - https://leetcode.com/problems/count-complete-tree-nodes/

# Solution - 

class Solution:
    def leftHeight(self, root):
        if root == None : return 0
        curr = root
        ans = 0
        while curr:
            ans += 1
            curr = curr.left
            
        return ans
    def rightHeight(self, root):
        if root == None : return 0
        curr = root
        ans = 0
        while curr:
            ans += 1
            curr = curr.right
            
        return ans
        
    def countNodes(self, root: Optional[TreeNode]) -> int:
        lh = self.leftHeight(root)
        rh = self.rightHeight(root)
        if lh == rh :
            return pow(2, lh)-1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
    
