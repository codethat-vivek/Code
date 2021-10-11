# Question Link - https://leetcode.com/problems/largest-substring-between-two-equal-characters/

# Solution - 

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        dt = dict()
        for i in range(len(s)):
            if s[i] not in dt:
                dt[s[i]] = [i]
            else:
                if len(dt[s[i]]) == 2:
                    dt[s[i]][1] = i
                else:
                    dt[s[i]].append(i)
        ans = -1
        for each in dt.values():
            if len(each) < 2:
                continue
            ans = max(ans, each[1]-each[0]-1)
            
        return ans
