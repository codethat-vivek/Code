// Question Link - https://leetcode.com/problems/generate-parentheses/

// Solution - 

class Solution:
    def insert(self, source_str, insert_str, pos):
        return source_str[:pos]+insert_str+source_str[pos:]
    def gen(self, n):
        if n == 1:
            return ["()"]
        ans = []
        s = self.gen(n-1) # list
        for each in s:
            for i in range(len(each)//2+1):
                ans.append(self.insert(each, "()", i))
        return ans
        
    def generateParenthesis(self, n: int) -> List[str]:
        temp = self.gen(n)
        st = set()
        for each in temp:
            st.add(each)
        return list(st)
