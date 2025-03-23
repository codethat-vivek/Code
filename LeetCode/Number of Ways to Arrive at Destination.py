# Question Link - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

# Solution - 

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adj = collections.defaultdict(list)
        for u, v, t in roads:
            adj[u].append((v, t))
            adj[v].append((u, t))
        
        INF = 10**20
        vis, dist = [0] * n, [INF] * n
        node = 0
        dist[node] = 0

        while not vis[node]:
            vis[node] = 1
            for childNode, timeTaken in adj[node]:
                if not vis[childNode]:
                    dist[childNode] = min(dist[childNode], dist[node] + timeTaken)
            
            minDist = INF
            for i in range(n):
                if not vis[i]:
                    if minDist > dist[i]:
                        minDist = dist[i]
                        node = i

        ways = [0] * n
        dist_copy = dist[:]
        vis[:], dist[:] = [0] * n, [INF] * n
        node = 0
        dist[node] = 0
        ways[node] = 1

        while not vis[node]:
            vis[node] = 1
            for childNode, timeTaken in adj[node]:
                if not vis[childNode]:
                    dist[childNode] = min(dist[childNode], dist[node] + timeTaken)
                    if dist[node] + timeTaken == dist_copy[childNode]:
                        ways[childNode] += ways[node]
            
            minDist = INF
            for i in range(n):
                if not vis[i]:
                    if minDist > dist[i]:
                        minDist = dist[i]
                        node = i
        
        return ways[n-1] % (10**9+7)
