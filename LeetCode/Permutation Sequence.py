# Question Link - https://leetcode.com/problems/permutation-sequence/

# Solution - 

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800]
        arr = ["0"]
        
        for i in range(1, n+1):
            arr.append(str(i))

        ans = ""
        
        while k != 0:
            t = k//(fact[n-1])
            r = k%(fact[n-1])

            if r == 0:
                ans += arr[t]
                arr.remove(arr[t])
                ans += (''.join(arr[1:][::-1]))
            else:
                ans += arr[t+1]
                arr.remove(arr[t+1])
            
            k = r
            n -= 1
            
        return ans
