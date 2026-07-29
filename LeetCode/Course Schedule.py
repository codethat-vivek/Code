# Question Link - https://leetcode.com/problems/course-schedule/description

# Solution - 

class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        adj = collections.defaultdict(list)
        indegree = [0]*n
        for u, v in prerequisites:
            adj[v].append(u)
            indegree[u] += 1
        

        q = collections.deque()
        processedNodes = 0

        for course, deg in enumerate(indegree):
            if deg == 0:
                q.append(course)
        
        while q:
            parentCourse = q.popleft()
            processedNodes += 1
            for childCourse in adj[parentCourse]:
                indegree[childCourse] -= 1
                if indegree[childCourse] == 0:
                    q.append(childCourse)
        
        return processedNodes == n
        
