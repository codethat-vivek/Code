# Question Link - https://leetcode.com/problems/maximum-width-of-binary-tree/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, data):
        if root == None:
            return
        root.val = data
        self.helper(root.left, 2*data)
        self.helper(root.right, 2*data+1)
        
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0
        if root.val == None and root.right == None: return 1
        
        self.helper(root, 1);
        ans = 0
        
        from collections import deque
        q = deque()
        q.append(root)
        while len(q) != 0:
            size = len(q)
            start, end, seen = 0, 0, 0
            while size != 0:
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    end = node.left.val
                    seen+=1
                    if seen == 1:
                        start = node.left.val
                if node.right:
                    q.append(node.right)
                    end = node.right.val
                    seen += 1
                    if seen == 1:
                        start = node.right.val
                size -= 1     
            ans = max(ans, end-start+1);
        return ans   
