# Question Link - https://leetcode.com/problems/intersection-of-two-linked-lists/

# Solution - 

class Solution:
    def getLength(self, head):
        ans = 0
        while head:
            ans += 1
            head = head.next
        return ans
    
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        m = self.getLength(headA)
        n = self.getLength(headB)
        if m < n:
            return self.getIntersectionNode(headB, headA)
        times = m - n
        while times != 0:
            headA = headA.next
            times -= 1
        
        while headA != None and headB != None and headA != headB:
            headA = headA.next
            headB = headB.next
        if headA == headB:
            return headA
        return None
