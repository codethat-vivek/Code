# Question Link - https://leetcode.com/problems/minimum-genetic-mutation/

# Solution - 

class Solution:
    def minMutation(self, startWord: str, targetWord: str, bank: List[str]) -> int:
        if targetWord not in bank:
            return -1
        def differByOne(a, b):
            d = 0
            for i in range(len(a)):
                if a[i] != b[i]:
                    d += 1
                if d > 1 : break
            return d == 1
        
        def f(currWord):
            if currWord == targetWord:
                return 0
            ans = 10**10
            for each in bank:
                if differByOne(currWord, each):
                    bank.remove(each)
                    ans = min(ans, 1+f(each))
                    bank.append(each)
            return ans
        
        ans = f(startWord)
        if ans >= 10**10 : return -1
        return ans
