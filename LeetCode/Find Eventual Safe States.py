# Question Link - https://leetcode.com/problems/find-eventual-safe-states/

# Solution - 

class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        vis = [0]*n
        isSafe = [0]*n
        for i in range(n):
            if graph[i] == []:
                vis[i] = 1
                isSafe[i] = 1
        
        def dfs(node):
            flag = False
            for child in graph[node]:
                if vis[child]:
                    if not isSafe[child]:
                        # child is not safe and hence node is also not safe
                        flag = True
                        break
                if not vis[child]:
                    vis[child] = 1
                    dfs(child)
                    if not isSafe[child]:
                        flag = True
                        break
                
            if not flag:
                isSafe[node] = 1
        
        for i in range(n):
            if not vis[i]:
                dfs(i)
        
        # print(isSafe)
        return [i for i, x in enumerate(isSafe) if x == 1]

        
