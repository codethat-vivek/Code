# Question Link - https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

# Solution - 

class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[v].append(u)
            adj[u].append(v)
        
        sum = [0]*n

        def dfs(node, parent):
            for child in adj[node]:
                if child != parent:
                    sum[node] += dfs(child, node)
            sum[node] += values[node]
            return sum[node]

        dfs(0, None)
        ans = 0
        print(sum)
        for u, v in edges:
            x = min(sum[u], sum[v])
            if x % k == 0 and (sum[0]-x)%k == 0:
                ans += 1
        
        return ans+1
