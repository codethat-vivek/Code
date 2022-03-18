# Question Link - https://leetcode.com/problems/remove-duplicate-letters/

# Solution - 

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        '''
        dbbacaebacdaeab
        abcde
        '''
        stack = []
        indices = [[] for _ in range(27)]
        for i, c in enumerate(s):
            indices[ord(c) - ord('a')].append(i)
    
        for i in range(len(s)):
            if len(stack) == 0:
                stack.append(s[i])
                continue
            if s[i] in stack:
                continue
            if stack[-1] < s[i]:
                stack.append(s[i])
            else:
                while len(stack) != 0 and stack[-1] > s[i] and indices[ord(stack[-1]) - ord('a')][-1] > i:
                    stack.pop(-1)
                stack.append(s[i])
            #print(stack)
        
        return ''.join(stack)

    
                
