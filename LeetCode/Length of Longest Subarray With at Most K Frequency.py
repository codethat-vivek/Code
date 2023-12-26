# Question Link - https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

# Solution - 

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans, cnt, i, j, n = 0, 0, 0, 0, len(nums)
        dt = dict()
        while j < n:
            if nums[j] not in dt or dt[nums[j]] == 0:
                dt[nums[j]] = 1
                cnt += 1
                ans = max(ans, cnt)
            else:
                if dt[nums[j]] == k:
                    while dt[nums[j]] >= k:
                        dt[nums[i]] -= 1
                        cnt -= 1
                        i += 1
                    dt[nums[j]] += 1
                    cnt += 1
                    ans = max(ans, cnt)
                else:
                    dt[nums[j]] += 1
                    cnt += 1
                    ans = max(ans, cnt)
            j += 1
        return ans
