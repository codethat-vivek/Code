# Question Link - https://leetcode.com/problems/continuous-subarray-sum/

# Solution -

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(n):
            nums[i] %= k
        prefixSum = [nums[0]]
        for i in range(1, n):
            prefixSum.append((prefixSum[-1]+nums[i])%k)

        # Now that we have prefixSum modulo k
        # We need to check whether any subarray sums to k in prefixSum --- Count Subarray with given sum
        
        dt = dict()
        dt[0] = -1
        for i in range(n):
            if prefixSum[i] in dt:
                if i - dt[prefixSum[i]] >= 2:
                    return True
            dt[prefixSum[i]] = i
        
        for i in range(n-1):
            if nums[i] == nums[i+1] == 0 : return True
        
        return False
            
