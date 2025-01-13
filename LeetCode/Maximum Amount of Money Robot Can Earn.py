# Question Link - https://leetcode.com/problems/minimum-length-of-string-after-operations/

# Solution - 

class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        arr = [0]*26
        for c in s:
            idx = ord(c)-ord('a')
            arr[idx] += 1
            if arr[idx] == 3:
                arr[idx] = 1
        return sum(arr)
