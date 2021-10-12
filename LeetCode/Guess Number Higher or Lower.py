# Question Link - https://leetcode.com/problems/guess-number-higher-or-lower/

# Solution - 

class Solution:
    def helper(self, start, end):
        mid =  start + (end - start)//2
        poss = guess(mid)
        if poss == 0:
            return mid
        if poss == -1:
            return self.helper(1, mid-1)
        if poss == 1:
            return self.helper(mid+1, end)
    def guessNumber(self, n: int) -> int:
        ans =  self.helper(1, n)
        return ans
