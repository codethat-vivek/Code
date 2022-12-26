# Question Link - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/

# Solution - 

class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if target not in words : return -1
        if words[startIndex] == target : return 0
        i, n, idx = 0, len(words), startIndex
        dist = n+1
        while i<n:
            i += 1
            nxt = words[(idx+1)%n]
            if nxt == target:
                dist = min(dist, i)
            idx += 1
        
        i, idx = 0, startIndex
        while i<n:
            i += 1
            prev = words[(idx-1+n)%n]
            if prev == target:
                dist = min(dist, i)
            idx -= 1
        
        return dist
            
