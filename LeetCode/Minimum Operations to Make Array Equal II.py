# Question Link - https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/

# Solution - 

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        '''
        4 3 1 4 => 1 3 4 4 => 1 3 7 1
        3 0 -6 3
        
        '''
        if k == 0:
            if nums1 == nums2:
                return 0
            return -1
        diff = [n1 - n2 for n1, n2 in zip(nums1, nums2)]
        if sum(diff) != 0:
            return -1
        div = [d/k for d in diff]
        if sum(div) != 0:
            return -1
        ans = 0
        for d in div:
            ans += abs(d)
        if ans % 2 != 0:
            return -1
        return int(ans/2)
        
