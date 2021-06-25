# Question Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

# Solution ->

# (BY CREATING OUR OWN LOWER BOUND AND UPPER BOUND FUNCTION)
# (COULD HAVE USED BISECT MODULE ALSO)

class Solution:
    def lower_bound(self, arr, target, low, high):
        n = len(arr)
        while low < high:
            mid = low + (high - low)//2
            if arr[mid] >= target:
                high = mid
            else:
                low = mid+1
        if low < n and arr[low] < target:
            return low+1
        return low
    
    def upper_bound(self, arr, target, low, high):
        n = len(arr)
        while low < high:
            mid = low + (high - low)//2
            if arr[mid] <= target:
                low = mid+1
            else:
                high = mid
        if low < n and arr[low] <= target:
            return low + 1
        return low
    
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        lb = self.lower_bound(nums, target, 0, n)
        ub = self.upper_bound(nums, target, 0, n)
        
        if lb == ub:
            return [-1, -1]
        
        else:
            return [lb, ub-1]   
   
