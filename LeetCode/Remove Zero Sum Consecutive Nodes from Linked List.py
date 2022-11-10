# Question Link - https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

# Solution - 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def intersect(self, p, q):
        return q[0] <= p[1]
    
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        from sortedcontainers import SortedList
        temp, arr = head, []
        while temp:
            arr.append(temp.val)
            temp = temp.next
        n, sm = len(arr), 0
        dt = dict()
        dt[0] = -1
        toBeDeleted = SortedList([])
        for i in range(n):
            sm += arr[i]
            if sm not in dt:
                dt[sm] = i
            else:
                toBeDeleted.add((dt[sm]+1, i))
                dt[sm] = i
        #print(toBeDeleted)
        
        finalToBeDeleted = []
        
        
        for i in range(len(toBeDeleted)):
            if i == 0 or not self.intersect(finalToBeDeleted[-1], toBeDeleted[i]):
                finalToBeDeleted.append(toBeDeleted[i])
            
        print(finalToBeDeleted)
        
        if not finalToBeDeleted:
            return head
        
        finalList = []
        i = idx = 0
        while i < n and idx < len(finalToBeDeleted):
            if i < finalToBeDeleted[idx][0]:
                finalList.append(arr[i])
                i += 1
            elif i == finalToBeDeleted[idx][0]:
                i = finalToBeDeleted[idx][1]+1
                idx += 1
        
        while i<n:
            finalList.append(arr[i])
            i += 1
            
        
        print(finalList)
        
        ans = ListNode(-1)
        temp = ans
        for e in finalList:
            temp.next = ListNode(e)
            temp = temp.next
        return ans.next
        
