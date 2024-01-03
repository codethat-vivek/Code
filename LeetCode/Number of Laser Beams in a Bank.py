# Question Link - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

# Solution - 

class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        i, ans = 0, 0
        lastCnt = 0
        m = len(bank)
        
        while i < m:
            lastCnt = bank[i].count('1')
            if lastCnt:
                break
            i += 1
        
        i += 1
        
        while i < m:
            currCnt = bank[i].count('1')
            ans += lastCnt*currCnt
            if currCnt:
                lastCnt = currCnt
            i += 1
        
        return ans
        
