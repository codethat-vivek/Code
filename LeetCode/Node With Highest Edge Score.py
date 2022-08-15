# Question Link - https://leetcode.com/problems/node-with-highest-edge-score/

# Solution - 

class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        n = len(edges)
        score = [0]*n
        
        for i in range(n):
            score[edges[i]] += i
        
        return score.index(max(score))
