# Question Link - https://leetcode.com/problems/largest-palindromic-number/

# Solution - 

class Solution:
    def largestPalindromic(self, num: str) -> str:
        if num == '0'*len(num):
            return '0'
        arr = [0 for _ in range(10)]
        for i in num:
            arr[ord(i)-ord('0')]+=1
        
        idx = 9
        ans = ""
        while idx >= 0:
            if idx == 0 and ans == "":
                break
            if arr[idx] > 1:
                times = arr[idx] // 2
                arr[idx] -= (2*times)
                ans += (str(idx)*times)
            idx -= 1
        
        idx = 9
        odd = False
        while idx >= 0:
            if arr[idx] == 1:
                ans += str(idx)
                odd = True
                break
            idx -= 1
        
        if not odd:
            return ans + ans[::-1]
        
        return ans + ans[:-1][::-1]
       
