# Question Link - https://leetcode.com/problems/ugly-number-ii/

# Solution - 

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        
        arr = [1]
        i=j=k=0
        while len(arr) != n:
            num = min(arr[i]*2, arr[j]*3, arr[k]*5)
            if num == arr[i]*2:
                i += 1
            if num == arr[j]*3:
                j += 1
            if num == arr[k]*5:
                k += 1
            arr.append(num)
        return arr[-1]
        
        
