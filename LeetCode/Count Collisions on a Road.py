# Question Link - https://leetcode.com/problems/count-collisions-on-a-road/

# Solution - 

class Solution:
    def countCollisions(self, directions: str) -> int:
        ans, cnt, n = 0, 0, len(directions)
        for i in range(n):
            if directions[i] == 'R':
                cnt += 1
            else:
                ans += cnt
                cnt = 0
        cnt = 0
        for i in range(n-1, -1, -1):
            if directions[i] == 'L':
                cnt += 1
            else:
                ans += cnt
                cnt = 0
        
        return ans
