# Question Link - https://leetcode.com/problems/jewels-and-stones/submissions/

# Solution - 

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        ans = 0
        for each in jewels:
            ans += (stones.count(each))
        return ans
