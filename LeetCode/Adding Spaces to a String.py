# Question Link = https://leetcode.com/problems/adding-spaces-to-a-string/

# Solution - 

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans, x, n = "", 0, len(spaces)
        spaces.append(len(s))
        for i in range(n+1):
            ans += s[x:spaces[i]]
            if i != n:
                ans += " "
            x = spaces[i]
                
        return ans
