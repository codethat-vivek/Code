# Question Link - https://leetcode.com/problems/combinations/submissions/

# Solution - 

class Solution:
    def helper(self, arr, i, n, k):
        if k == 0:
            return [[]]
        if k == n-i:
            return [arr[i:]]
        if k > n-i:
            return [[]]
        
        f = self.helper(arr, i+1, n, k)
        s = self.helper(arr, i+1, n, k-1)
        
        for j in range(len(s)):
            s[j].append(arr[i])

        return f+s
        
        
    def combine(self, n: int, k: int) -> List[List[int]]:
        arr = [i for i in range(1, n+1)]
        return self.helper(arr, 0, n, k)        
