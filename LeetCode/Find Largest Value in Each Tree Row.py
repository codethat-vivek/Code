# Question Link - https://leetcode.com/problems/find-largest-value-in-each-tree-row/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root == None : return []
        from collections import deque
        queue = deque([root])
        ans = []
        while len(queue):
            mx, size = -10**10, len(queue)
            while size:
                size -= 1
                node = queue.popleft()
                mx = max(mx, node.val)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            ans.append(mx)
        return ans
      
