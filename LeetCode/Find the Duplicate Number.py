# Question Link - https://leetcode.com/problems/find-the-duplicate-number/

# Solution - 

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Time - O(n)
        # Space - O(1)
        # Without modifying the array
        
        slow = fast = nums[0]
        
        while True: # python do while
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        fast = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        
        return slow
        
