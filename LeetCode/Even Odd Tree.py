# Question Link - https://leetcode.com/problems/even-odd-tree/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if root is None:
            return True
        import queue
        q = queue.Queue()
        q.put(root)
        lvl = 0
        
        while not q.empty():
            size = q.qsize()
            if lvl == 0:
                prev = -1
            else:
                prev = 1e6+1
            while size != 0:
                x = q.get()
                if x.left :
                    q.put(x.left)
                if x.right:
                    q.put(x.right)
                if lvl % 2 == 0:
                    if x.val % 2 == 0 or prev >= x.val:
                        return False
                if lvl % 2 != 0:
                    if x.val % 2 != 0 or prev <= x.val:
                        return False
                prev = x.val
                size -= 1
            lvl ^= 1
        return True
                
                
