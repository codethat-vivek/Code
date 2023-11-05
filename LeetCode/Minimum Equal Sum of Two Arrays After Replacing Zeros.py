# Question Link - https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

# Solution - 

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        first, second = nums1.count(0), nums2.count(0)
        fsm, ssm = sum(nums1), sum(nums2)
        
        #print(first, second, fsm, ssm)
        
        if first == 0 and second == 0:
            if fsm == ssm:
                return fsm
            return -1
        
        if first == 0:
            if second + ssm <= fsm:
                return fsm
            return -1
            
        if second == 0:
            if first + fsm <= ssm:
                return ssm
            return -1
        
        return max(fsm + first, ssm + second)
