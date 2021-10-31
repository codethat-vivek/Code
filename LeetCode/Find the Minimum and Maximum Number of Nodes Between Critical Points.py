# Question Link - https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

# Solution - 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        arr = []
        curr = head
        while curr:
            arr.append(curr.val)
            curr = curr.next
        minima, maxima = [], []
        for i in range(1, len(arr)-1):
            if arr[i] < arr[i-1] and arr[i] < arr[i+1]:
                minima.append(i)
            if arr[i] > arr[i-1] and arr[i] > arr[i+1]:
                maxima.append(i)
        mm = minima+maxima
        if len(mm) < 2 : return [-1, -1]
        mm.sort()
        diff = int(1e9+7)
        for i in range(1, len(mm)):
            diff = min(diff, mm[i]-mm[i-1])
        return [diff, mm[-1]-mm[0]]
        
