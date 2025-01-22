# Question Link - https://leetcode.com/problems/map-of-highest-peak/

# Solution - 

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        r, c = len(isWater), len(isWater[0])
        dq = deque()
        for i in range(r):
            for j in range(c):
                if isWater[i][j] == 1:
                    isWater[i][j] = 0
                    dq.append((i, j))
                else:
                    isWater[i][j] = -1
        
        dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]

        while len(dq) > 0:
            size = len(dq)
            while size:
                size -= 1
                x, y = dq.popleft()
                for dx, dy in dirs:
                    nx, ny = x+dx, y+dy
                    if 0 <= nx < r and 0 <= ny < c and isWater[nx][ny] == -1:
                        isWater[nx][ny] = isWater[x][y] + 1
                        dq.append((nx, ny))
        
        return isWater
