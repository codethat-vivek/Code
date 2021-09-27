# Question Link - https://leetcode.com/problems/repeated-dna-sequences/

# Solution - 

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        n = len(s)
        dt = dict()
        i = j = 0
        while j < n:
            if j - i + 1 < 10:
                j += 1
            elif j - i + 1 == 10:
                sub = s[i:j+1]
                if sub not in dt:
                    dt[sub] = 1
                else:
                    dt[sub] += 1
                i += 1
                j += 1
        ans = []
        for x in dt:
            if dt[x] > 1:
                ans.append(x)
        return ans
