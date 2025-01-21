# Question Link - https://leetcode.com/problems/grid-game/description/

# Solution - 

class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        arr, brr = grid[0], grid[1]
        parr, pbrr = [0]*n, [0]*n
        parr[0], pbrr[0] = arr[0], brr[0]
        asm, bsm = sum(arr), sum(brr)
        for i in range(1, n):
            parr[i] = parr[i-1] + arr[i]
            pbrr[i] = pbrr[i-1] + brr[i]
        
        ans = 10**20

        for i in range(n):
            opt1 = asm-parr[i]
            opt2 = pbrr[i-1] if i != 0 else 0
            ans = min(ans, max(opt1, opt2))
            # print(i, opt1, opt2, ans)
        
        return ans
