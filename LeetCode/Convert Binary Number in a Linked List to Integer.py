# Question Link - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

# Solution - 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        arr = []
        while head:
            arr.append(head.val)
            head  = head.next
        for i in range(len(arr)):
            arr[i] = str(arr[i])
        return int(''.join(arr), 2)
