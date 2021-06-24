# Question Link - https://leetcode.com/problems/unique-morse-code-words/

# Solution - 

class Solution:
    
    def transformation(self, s):
        d = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        t = ""
        for each in s:
            t += d[(ord(each)-97)]
        return t;
    
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        l = set()
        for word in words:
            l.add(self.transformation(word))
        return len(l)
