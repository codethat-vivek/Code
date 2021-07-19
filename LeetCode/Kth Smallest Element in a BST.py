# Question Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/

# Solution - 

class Solution:
    def helper(self, root, k, arr):
        # this function insert every node val in arr
        if root is None:
            return
        
        self.helper(root.left, k, arr)
        arr.append(root.val)
        self.helper(root.right, k, arr)
        
        return
        
        
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        arr = []
        self.helper(root, k, arr)
        print(arr)
        t =  arr[k-1]
        return t
        
