# Question Link - https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

# Solution - 

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        a = [False for i in range(n)]
        for x, y in edges:
            a[y] = True
        b = []
        for i in range(len(a)):
            if a[i] == False : b.append(i)
        #print(b)
        return b
