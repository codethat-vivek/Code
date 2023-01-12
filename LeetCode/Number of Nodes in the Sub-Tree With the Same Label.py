# Question Link - https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

# Solution - 

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        
        ans = [0 for _ in range(n)]
        vis = [False for _ in range(n)]
        
        def dfs(node):
            vis[node] = True
            dt = collections.defaultdict(int)
            for child in adj[node]:
                if not vis[child]:
                    c = dfs(child)
                    for char in c:
                        dt[char] += c[char]
            dt[labels[node]] += 1
            ans[node] = dt[labels[node]]
            return dt
        
        
        dfs(0)
        return ans
            
                    
        
