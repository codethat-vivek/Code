# Question Link - https://leetcode.com/problems/n-ary-tree-level-order-traversal/

# Solution - 

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root == None:
            return []
        import queue
        q = queue.Queue()
        ans = []
        q.put(root)
        while q.qsize() != 0:
            size = q.qsize()
            temp = []
            for i in range(size):
                p = q.get()
                lt = p.children
                for each in lt:
                    if each is not None:
                        q.put(each)
                temp.append(p.val)
            ans.append(temp)
        return ans
