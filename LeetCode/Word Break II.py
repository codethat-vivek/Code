# Question Link - https://leetcode.com/problems/word-break-ii/

# Solution - 

class Solution:
    def allConstruct(self, wordBank, target, memo):
        if target in memo:
            return memo[target]
        ans = []
        if target == "":
            return [[]]
        for word in wordBank:
            try:
                if target.index(word) == 0:
                    suffix = target[len(word):]
                    subWays = self.allConstruct(wordBank, suffix, memo)
                    for each in subWays:
                        ans.append([word]+each)
            except ValueError:
                continue
        memo[target] = ans
        return ans
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        temp = self.allConstruct(wordDict, s, {})
        ans = []
        for each in temp:
            t = ""
            for word in each:
                t += word
                t += " "
            ans.append(t[:-1])
        return ans
        
