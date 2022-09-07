# Question Link - 

# Solution - 

class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        
        def traverseAndCreate(root):
            if root == None : return ""
            lp = traverseAndCreate(root.left)
            rp = traverseAndCreate(root.right)
            if lp == "" and rp == "":
                return str(root.val)
            if lp == "":
                return str(root.val) + "()" + "(" + rp + ")"
            if rp == "":
                return str(root.val) + "(" + lp + ")"
            return str(root.val) + "(" + lp + ")" + "(" + rp + ")"
        
        return traverseAndCreate(root)
