# Question Link - https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

# Solution - 

"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def helper(self, head):
        if head == None : return None, None
        if head.child == None and head.next == None : return head, head
        ans = Node(head.val)
        finalans = ans
        node, tail = self.helper(head.child)
        if node != None:
            ans.next = node
            node.prev = ans
            ans = tail
        node, tail = self.helper(head.next)
        if node != None:
            ans.next = node
            node.prev = ans
            ans = tail
        return finalans, ans
        
        
    def flatten(self, head: 'Node') -> 'Node':
        a, b =  self.helper(head)
        return a
