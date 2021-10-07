# Question Link - https://leetcode.com/problems/find-missing-observations/

# Solution - 

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        total_sum = mean*(m+n)
        required_sum = total_sum - sum(rolls)
        if required_sum < n or required_sum > 6*n:
            return []
        each = required_sum // n
        ans = [each for i in range(n)]
        rem = required_sum - each*n
        i = 0
        while rem:
            ans[i] += 1
            i += 1
            rem -= 1
        return ans
