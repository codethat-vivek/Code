# Question Link - https://leetcode.com/problems/find-champion-ii/

# Solution - 

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        arr = [0]*n
        for u,v in edges:
            arr[v]+=1
        
        ans= []
        for i,e in enumerate(arr):
            if e==0:
                ans.append(i)
        if len(ans)>1:
            return -1
        return ans[0]
