# Question Link - https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

# Solution - 

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        st = {'a', 'e', 'i', 'o', 'u'}
        n = len(words)
        pref = [0]*n
        for i, word in enumerate(words):
            if i == 0:
                if word[0] in st and word[-1] in st:
                    pref[0] = 1
            else:
                if word[0] in st and word[-1] in st:
                    pref[i] = pref[i-1] + 1
                else:
                    pref[i] = pref[i-1]
        
        ans = []
        for u, v in queries:
            if u != 0:
                ans.append(pref[v]-pref[u-1])
            else:
                ans.append(pref[v])
        
        return ans
