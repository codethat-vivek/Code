# Question Link - https://leetcode.com/problems/custom-sort-string/

# Solution - 

class Solution:
    def customSortString(self, order: str, str: str) -> str:
        arr = [0 for _ in range(26)]
        brr = [0 for _ in range(26)]
        
        for char in order:
            arr[ord(char)-97] += 1
        
        for char in str:
            brr[ord(char)-97] += 1
        
        ans = ""
        
        for char in order:
            if brr[ord(char)-97] != 0:
                times = brr[ord(char) - 97]
                ans += char*times
        
        # characters that are not present in order but are in str
        for char in str:
            if arr[ord(char)-97] == 0:
                ans += char
        
        return ans
