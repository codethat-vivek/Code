# Question Link - https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

# Solution - 

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        count = collections.Counter(tasks)
        ans = 0
        for task in count:
            val = count[task]
            if val < 2:
                return -1
            rem = val%3
            if rem == 0:
                ans += val//3
            elif rem == 1 or rem == 2:
                ans += val//3+1
        
        return ans
