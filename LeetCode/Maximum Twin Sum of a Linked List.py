# Question Link - https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

# Solution - 


class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        start = head
        arr = []
        while start is not None:
            arr.append(start.val)
            start = start.next
        
        ans = -1
        for i in range(0, len(arr)//2):
            ans = max(ans, arr[i] + arr[len(arr)-i-1])
        
        return ans
