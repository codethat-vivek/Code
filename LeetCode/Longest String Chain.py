# Question Link - https://leetcode.com/problems/longest-string-chain/

# Solution - 

class Solution:

    def longestStrChain(self, words: List[str]) -> int:
        
        def isPredecessor(word1, word2):
            if word1 == "":
                return True
            if len(word1)+1 != len(word2):
                return False
            i, j = 0, 0 # len(word1) < len(word2)
            first = False
            while i != len(word1):
                if word1[i] == word2[j]:
                    i += 1
                    j += 1
                elif not first:
                    first = True
                    j += 1
                else:
                    return False
            
            return True

        words.sort(key = len)
        
        def helper(idx, prev, dt):
            if idx == len(words):
                return 0
            
            key = str(idx)+prev
            
            if key in dt:
                return dt[key]
            
            if isPredecessor(prev, words[idx]): #possible to include in answer set
                dt[key] = max(1+helper(idx+1, words[idx], dt), helper(idx+1, prev, dt))
                return dt[key]
            
            dt[key] = helper(idx+1, prev, dt)
            return dt[key]
        
        return helper(0, "", {})
       
