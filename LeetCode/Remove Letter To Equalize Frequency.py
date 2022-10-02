# Question Link - https://leetcode.com/problemset/all/?search=remove+letter+to+&page=1

# Solution - 

class Solution:
    def equalFrequency(self, word: str) -> bool:
        for idx, char in enumerate(word):
            newString = word[:idx] + word[idx+1:]
            count = collections.Counter(newString)
            if len(set(count.values())) == 1 : return True
        return False

# Quite Bad Solution
