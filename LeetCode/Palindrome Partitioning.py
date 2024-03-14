# Question Link - https://leetcode.com/problems/palindrome-partitioning/

# Solution - 

class Solution:
    
    def __init__(self):
        self.dt = dict()
    
    def isPalindrome(self, s, i, j):
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
    
    
    def helper(self, s, i, j):
        # Base Condition
        if i > j:
            return [[]]
        if i == j:
            return [[s[i]]]
        
        if (i, j) in self.dt:
            return self.dt[(i, j)]
        
        st, ans = set(), []
        if self.isPalindrome(s, i, j):
            st.add(tuple([s[i:j+1]]))
        
        for k in range(i, j):
            first = self.helper(s, i, k)
            second = self.helper(s, k+1, j)
            for x in first:
                for y in second:
                    st.add(tuple(x)+tuple(y))
        
        for each in st:
            ans.append(list(each))
        
        self.dt[(i, j)] = ans
        
        return ans
    
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        return list(self.helper(s, 0, n-1))
