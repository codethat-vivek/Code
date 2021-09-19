# Question Link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

# Solution - 

class Solution:
    
    def create(self, arr):
        if len(arr) == 0:
            return None
        mid = (0+len(arr)-1)//2
        root = TreeNode(arr[mid])
        lp = self.create(arr[:mid])
        rp = self.create(arr[mid+1:])
        root.left = lp
        root.right = rp
        return root
    
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        arr = []
        temp = head
        while temp:
            arr.append(temp.val)
            temp = temp.next
        root = self.create(arr)
        return root
