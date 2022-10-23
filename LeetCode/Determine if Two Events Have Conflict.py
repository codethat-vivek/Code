# Question Link - https://leetcode.com/problems/determine-if-two-events-have-conflict/

# Solution - 

class Solution:
    def helper(self, p, q):
        # returns -
        # 1 if p is smaller
        # 2 if q is smaller
        # 0 if p = q
        
        ph, pm = int(p[:2]), int(p[3:])
        qh, qm = int(q[:2]), int(q[3:])
        
        if ph < qh:
            return 1
        if ph > qh:
            return 2

        if pm < qm : 
            return 1
        if pm > qm : 
            return 2
        return 0

            
        
        
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        x = self.helper(event1[0], event2[0])
        
        if x == 2:
            return self.haveConflict(event2, event1)
        x = self.helper(event1[1], event2[0])
        if x == 2 or x == 0:
            return True
        return False
        
            
        
