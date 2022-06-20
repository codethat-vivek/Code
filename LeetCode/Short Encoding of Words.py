# Question Link - https://leetcode.com/problems/short-encoding-of-words/

# Solution - 

class Node:
    def __init__(self, c, isEnd = False):
        self.c = c
        self.isEnd = isEnd
        self.child = dict()
        
class Solution:
    def __init__(self):
        self.root = Node('#')
        
    def insert(self, word):
        curr = self.root
        for c in word:
            if c not in curr.child:
                curr.child[c] = Node(c)
            curr = curr.child[c]
        curr.isEnd = True
    
    def minimumLengthEncoding(self, words: List[str]) -> int:
        
        for word in set(words):
            self.insert(word[::-1])
        
        words = list(set(words))
        words.sort(key = len)
        ans = 0
        for word in words:
            word = word[::-1]
            curr = self.root
            for c in word:
                curr = curr.child[c]
            if len(curr.child) == 0:
                ans += (len(word) + 1)
        
        return ans
        
        
        
        
