# Question Link - https://leetcode.com/problems/excel-sheet-column-number/

# Solution - 

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        power = 0
        columnTitle = columnTitle[::-1]
        for each in columnTitle:
            ans += (ord(each)-64)*pow(26, power)
            power += 1
        return ans
