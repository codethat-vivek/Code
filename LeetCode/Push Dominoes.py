# Question Link - https://leetcode.com/problems/push-dominoes/

# Solution - 

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        big = int(1e9+7)
        left = [big]*n
        right = [big]*n
        
        k = big
        for i in range(n):
            # going from left to right and searching for R
            if dominoes[i] == 'R':
                k = 0
            elif dominoes[i] == 'L':
                k = big
            else:
                k += 1
            left[i] = min(left[i], k)
        
        k = big
        for i in range(n-1, -1, -1):
            if dominoes[i] == 'L':
                k = 0
            elif dominoes[i] == 'R':
                k = big
            else:
                k += 1
            right[i] = min(right[i], k)
        
        ans = ""
        for i in range(n):
            if left[i] < right[i]:
                ans += 'R'
            elif right[i] < left[i]:
                ans += 'L'
            else:
                ans += '.'
        return ans
