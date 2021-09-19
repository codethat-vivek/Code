# Question Link - https://leetcode.com/problems/binary-tree-postorder-traversal/

# Solution - 

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return []
        ans = []
        lp = self.postorderTraversal(root.left)
        rp = self.postorderTraversal(root.right)
        for each in lp:
            ans.append(each)
        for each in rp:
            ans.append(each)
        ans.append(root.val)
        return ans
