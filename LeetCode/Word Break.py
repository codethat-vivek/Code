# Question Link - https://leetcode.com/problems/word-break/

# Solution - 

class Solution:
    def helper(self, wordDict, target, dp):
        if target == "" : return True
        if target in dp : return dp[target]
        
        for word in wordDict:
            try:
                if target.index(word) == 0:
                    suffix = target[len(word):]
                    if self.helper(wordDict, suffix, dp):
                        dp[target] = True
                        return True
            except ValueError:
                continue
        dp[target] = False
        return False
        
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        return self.helper(wordDict, s, {})
