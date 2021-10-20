# Question Link - https://leetcode.com/problems/subtree-of-another-tree/

# Solution - 

class Solution:
    def isSubtree(self, root: Optional[TreeNode], sub: Optional[TreeNode]) -> bool:
        if not root : return False
        def f(root, sub):
            if root == None and sub == None : return True
            if root == None or sub == None : return False
            if root.val==sub.val and f(root.left, sub.left) and f(root.right, sub.right):
                return True
            return False
        if f(root, sub) or self.isSubtree(root.left, sub) or self.isSubtree(root.right, sub):
            return True
        return False
