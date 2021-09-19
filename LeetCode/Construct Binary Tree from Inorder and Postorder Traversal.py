# Question Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

# Solution - 

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(inorder) == 0:
            return None
        root = TreeNode(postorder[-1])
        idx = inorder.index(postorder[-1])
        lp = self.buildTree(inorder[:idx], postorder[:idx])
        rp = self.buildTree(inorder[idx+1:], postorder[idx:-1])
        root.left = lp
        root.right = rp
        return root
