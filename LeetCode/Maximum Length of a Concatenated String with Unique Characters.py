# Question Link - https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

# Solution - 

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        
        def intersect(p, q):
            a = [0]*26
            for each in p:
                if a[ord(each)-97] > 0 : return True
                a[ord(each)-97] = 1
            for each in q:
                if a[ord(each)-97] > 0 : return True
                a[ord(each)-97] = 1
            return False
        
        n = len(arr)
        ans = 0
        
        def f(idx, curr):
            nonlocal ans
            ans = max(ans, len(curr))
            
            if idx == n : return
            f(idx+1, curr)
            if not intersect(curr, arr[idx]):
                f(idx+1, curr+arr[idx])
            
            
        f(0, "")
        
        return ans
            
            
