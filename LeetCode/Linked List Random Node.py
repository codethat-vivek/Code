# Question Link - https://leetcode.com/problems/linked-list-random-node/

# Solution - 

class Solution:
    
    def __init__(self, head: Optional[ListNode]):
        self.arr = []
        while head:
            self.arr.append(head.val)
            head = head.next

    def getRandom(self) -> int:
        from random import randint as r
        idx = r(0, len(self.arr)-1)
        return self.arr[idx]
