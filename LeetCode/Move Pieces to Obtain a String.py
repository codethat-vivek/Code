# Question Link - https://leetcode.com/problems/move-pieces-to-obtain-a-string/

# Solution - 

class Solution:
    def canChange(self, start: str, target: str) -> bool:
        m, n = len(start), len(target)
        if m != n : return False
        
        def findOrder(arr):
            order = []
            for c in arr:
                if c != '_':
                    order.append(c)
            return order
        
        order = findOrder(start)
        if order != findOrder(target):
            return False
        
        
        lowerBound, upperBound = [-1]*len(order), [-1]*len(order)
        
        prev = j = 0
        for i in range(m):
            c = start[i]
            if c == '_': continue
            elif c == 'L':
                lowerBound[j] = prev
                upperBound[j] = i
                prev += 1
            elif c == 'R':
                lowerBound[j] = i
                prev = i+1
            j += 1
        
        
        j = len(order)-1
        while j >=0 and order[j] != 'R':
            j -= 1
        
        for i in range(m-1, -1, -1):
            if start[i] == 'R':
                if j == len(order)-1:
                    upperBound[j] = m-1
                else:
                    upperBound[j] = upperBound[j+1]-1
                j -= 1
                while j >= 0 and order[j] != 'R':
                    j -= 1
        
        idx = 0
        for i, c in enumerate(target):
            if c != '_':
                if not(lowerBound[idx] <= i <= upperBound[idx]):
                    return False
                idx += 1
        
                
        return True
        
