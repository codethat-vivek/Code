# Question Link - https://leetcode.com/problems/sum-of-even-numbers-after-queries/

# Solution - 

class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        s = sum(x for x in nums if x%2 == 0)
        for val, idx in queries:
            if nums[idx] % 2 == 0:
                if val % 2 == 0:
                    s += val
                else:
                    s -= nums[idx]
            else:
                if val % 2 != 0:
                    s += (nums[idx]+val)
            nums[idx] += val
            ans.append(s)
            
        return ans
