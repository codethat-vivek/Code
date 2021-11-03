# Question Link - https://leetcode.com/problems/sum-root-to-leaf-numbers/

# Solution - 

class Solution:
    def helper(self, root):
        if root == None:
            return []
        data = str(root.val)
        lp = self.helper(root.left)
        rp = self.helper(root.right)
        t = lp+rp
        for i in range(len(t)):
            t[i] = data + t[i]
        if t == []:
            return [data]
        return t
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return sum(map(int, self.helper(root)))
        
