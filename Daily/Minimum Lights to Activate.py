# Question Link - https://www.interviewbit.com/problems/minimum-lights-to-activate/

# Solution - 

class Solution:
  
    def solve(self, A, B):
        # i-k+1, i+k-1
        n = len(A)
        k = B
        bulbs = 0
        idx = 0
        
        while idx < n:
            j = min(idx+k-1, n-1)
            while j >= max(0, idx-k+1):
                if A[j] == 1:
                    break
                j -= 1
            if j == max(0, idx-k+1)-1 : 
                return -1
            bulbs += 1
            idx = (j+k)
        return bulbs
                
