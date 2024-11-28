# Question Link - https://leetcode.com/problems/remove-methods-from-project/

# Solution - 

class Solution:
    
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        for a, b in invocations:
            graph[a].append(b)
        sus = [0]*n
        #print(graph)
        def findSus(method):
            sus[method] = 1
            if graph[method] == []:
                return
            for child in graph[method]:
                if sus[child] != 1:
                    findSus(child)
        
        findSus(k) # all suspects found
        print(sus)
        
        visited = [0]*n
        def checkReach(method):
            visited[method] = 1
            if graph[method] == []: return False
            for child in graph[method]:
                if sus[child] == 1:
                    return True
                if visited[child] != 1 and checkReach(child):
                    return True
            return False
        
        #checking if we can reach any susects from the non-suspects
        for idx in range(n):
            if sus[idx] != 1 and visited[idx] == 0:
                if checkReach(idx):
                    return [i for i in range(n)]
        
        return [i for i,x in enumerate(sus) if x == 0]
