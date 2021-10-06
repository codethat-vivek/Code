# Question Link - https://leetcode.com/problems/delete-node-in-a-bst/

# Solution - 

class Solution:
    def findMinRoot(self, root):
        if root.left == None:
            return root
        return self.findMinRoot(root.left)
        
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else: # root.val == target
            if root.left == None and root.right == None: # Leaf node
                return None
            if root.left == None:
                return root.right
            if root.right == None:
                return root.left
            if root.left and root.right:
                minRoot = self.findMinRoot(root.right)
                root.val, minRoot.val = minRoot.val, root.val # Swap
                root.right = self.deleteNode(root.right, key)
        return root
                
