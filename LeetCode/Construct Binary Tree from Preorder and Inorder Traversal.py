# Question Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

# Solution - 

class Solution:
    
    def create(self, preorder, inorder):
        if len(preorder) <= 0:
            return None
 
        root = TreeNode(preorder[0])
        idx = inorder.index(preorder[0])
        lp = self.create(preorder[1 : idx+1], inorder[:idx])
        rp = self.create(preorder[idx+1:], inorder[idx+1:])
        root.left = lp
        root.right = rp
        return root
        
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        '''
        Level Order Traversal -> [1, 2, 3, 4, 5, 6, 7]
        Preorder Traversal    -> [1, 2, 4, 5, 3, 6, 7]
        Inorder Traversal     -> [4, 2, 5, 1, 6, 3, 7]
        
        '''
        
        root = self.create(preorder, inorder)
        return root
        
