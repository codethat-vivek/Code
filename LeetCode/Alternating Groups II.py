# Question Link - https://leetcode.com/problems/alternating-groups-ii/

# Solution - 

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        if colors[0] == colors[-1]:
            i = j = ans = 0
            while j < n:
                if colors[j] == colors[j-1]:
                    i = j
                    j += 1
                elif colors[j] != colors[j-1]:
                    if j - i + 1 == k:
                        ans += 1
                        i += 1
                        j += 1
                    else:
                        j += 1
            return ans
            
        else:
            colors = colors + colors
            i = j = ans = 0
            while i < n and j < 2*n:
                if colors[j] == colors[j-1]:
                    i = j
                    j += 1
                elif colors[j] != colors[j-1]:
                    if j - i + 1 == k:
                        ans += 1
                        i += 1
                        j += 1
                    else:
                        j += 1
            return ans

        
