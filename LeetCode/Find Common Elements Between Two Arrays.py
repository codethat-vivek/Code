# Question Link - https://leetcode.com/problems/find-common-elements-between-two-arrays/

# Solution - 

class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        a, b = list(set(nums1)), list(set(nums2))
        a, b = sorted(a), sorted(b)
        # print(a, b)
        i, j = 0, 0
        arr = []
        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                arr.append(a[i])
                i += 1
                j += 1
            elif a[i] < b[j]:
                i += 1
            else:
                j += 1
        
        ans = [0, 0]
        for e in arr:
            ans[0] += nums1.count(e)
            ans[1] += nums2.count(e)
        
        return ans
