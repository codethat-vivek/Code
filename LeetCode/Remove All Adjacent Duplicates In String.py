# Question Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

# Solution - 

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for each in s:
            if not stack:
                stack.append(each)
            else:
                if stack[-1] == each:
                    stack.pop()
                else:
                    stack.append(each)
        ans = ""
        while stack:
            ans += (stack[-1])
            stack.pop()
        return ans[::-1]
