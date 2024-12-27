# Question Link - https://leetcode.com/problems/minimum-height-trees/

# Solution - 

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        INF = 10**20
        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        def bfs(node):
            q = collections.deque()
            q.append(node)
            dist = [INF]*n
            dist[node] = 0
            while len(q) > 0:
                size = len(q)
                while size:
                    size -= 1
                    frontNode = q.popleft()
                    for child in adj[frontNode]:
                        if dist[child] == INF:
                            q.append(child)
                            dist[child] = dist[frontNode] + 1
            return dist
        
        distFromZero = bfs(0)
        firstEndOfDiameter = distFromZero.index(max(distFromZero))
        # print(firstEndOfDiameter)
        distFromFirstEnd = bfs(firstEndOfDiameter)
        secondEndOfDiameter = distFromFirstEnd.index(max(distFromFirstEnd))
        # print(secondEndOfDiameter)
        curr_node = secondEndOfDiameter
        path = []
        while curr_node != firstEndOfDiameter:
            path.append(curr_node)
            for child in adj[curr_node]:
                if distFromFirstEnd[child] == distFromFirstEnd[curr_node] -1:
                    curr_node = child
                    break
        path.append(firstEndOfDiameter)
        centralNodes = []
        x = len(path)
        if x % 2 == 0:
            centralNodes += path[x//2-1:x//2+1]
        else:
            centralNodes.append(path[x//2])
        
        return centralNodes
