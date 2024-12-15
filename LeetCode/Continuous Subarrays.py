# Question Link - https://leetcode.com/problems/continuous-subarrays/

# Solution - 

class Solution:
    def continuousSubarrays(self, nums):
        n = len(nums)
        i = 0
        j = 0
        mn = nums[0]
        mx = nums[0]
        tmx, tmn, ptmx, ptmn = 0, 0, 0, 0
        ans = 0
        
        while j < n:
            if abs(mx - nums[j]) <= 2 and abs(mn - nums[j]) <= 2:
                mx = max(mx, nums[j])
                mn = min(mn, nums[j])
                j += 1
            else:
                ans += (j - i) * (j - i + 1) // 2
                tmx = nums[j]
                tmn = nums[j]
                i = j
                while abs(nums[j] - tmx) <= 2 and abs(nums[j] - tmn) <= 2:
                    i -= 1
                    ptmx = tmx
                    ptmn = tmn
                    tmx = max(tmx, nums[i])
                    tmn = min(tmn, nums[i])
                i += 1
                mx = ptmx
                mn = ptmn
                ans -= (j - i) * (j - i + 1) // 2
                j += 1
        
        ans += (j - i) * (j - i + 1) // 2
        
        return ans
