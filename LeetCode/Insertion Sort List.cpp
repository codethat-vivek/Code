// Question Link - https://leetcode.com/problems/insertion-sort-list/

// Solution - 

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next : 
            return head
        curr = head.next
        curr_prev = head
        while curr:
            #temp = curr
            itr = head
            prev = None
            while itr != curr and curr.val >= itr.val:
                prev = itr
                itr = itr.next
            entered = False
            if curr.val < itr.val:
                entered = True
                curr_prev.next = curr.next
                if not prev:
                    curr.next = itr
                    head = curr
                else:
                    prev.next = curr
                    curr.next = itr
            if not entered:
                curr_prev = curr
                curr = curr.next
            else:
                curr = curr_prev.next
        return head
