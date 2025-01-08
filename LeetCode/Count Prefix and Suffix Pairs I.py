# Question Link - 

# Solution -

class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        ans = 0
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                x, y = words[i], words[j]
                if y.find(x) == 0 and y[::-1].find(x[::-1]) == 0:
                    ans += 1

        return ans
