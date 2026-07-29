# Question Link - https://leetcode.com/problems/course-schedule-ii/description

# Solution - 

class Solution:
    def findOrder(self, n: int, prerequisites: List[List[int]]) -> List[int]:
        adj = collections.defaultdict(list)
        for u, v in prerequisites:
            adj[v].append(u)

        topo = []
        def dfs(node):
            visiting[node] = 1
            for child in adj[node]:
                if visiting[child] == 1:
                    return 0
                if visited[child] == 0:
                    d = dfs(child)
                    if d == 0:
                        return 0
                
            topo.append(node)
            visited[node] = 1
            visiting[node] = 0
            return 1

        visited = [0]*n
        visiting = [0]*n

        for course in range(n):
            if visited[course] == 0:
                d = dfs(course)
                if d == 0:
                    return []
        return topo[::-1]
        
       
