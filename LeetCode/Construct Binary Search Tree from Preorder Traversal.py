# Question Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

# Solution - 

class Solution:
    def create(self, preorder, start, end):
        if start > end:
            return None
        if start == end:
            return TreeNode(preorder[start])
        root = TreeNode(preorder[start])
        idx = end+1
        for i in range(start+1, end+1):
            if preorder[i] > preorder[start]:
                idx = i
                break
        root.left = self.create(preorder, start+1, idx-1)
        root.right = self.create(preorder, idx, end)
        return root
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        return self.create(preorder, 0, len(preorder)-1)
