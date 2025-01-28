# Question Link - https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

# Solution - 

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        

        def bfs(grid, r, c, x, y, vis):
            q = collections.deque()
            q.append((grid[x][y], x, y))
            dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
            vis[x][y] = 1
            res = 0
            while q:
                sz = len(q)
                while sz:
                    sz -= 1
                    val, x, y = q.popleft()
                    res += val
                    for dx, dy in dirs:
                        nx, ny = x+dx, y+dy
                        if 0<=nx<r and 0<=ny<c and not vis[nx][ny] and grid[nx][ny] != 0:
                            q.append((grid[nx][ny], nx, ny))
                            vis[nx][ny] = 1
            return (res, vis)
        

        vis = [[0]*c for _ in range(r)]
        ans = 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] != 0:
                    val, visited = bfs(grid, r, c, i, j, vis)
                    ans = max(ans, val)
                    vis = visited
        
        return ans
