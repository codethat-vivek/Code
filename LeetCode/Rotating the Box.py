# Question Link - https://leetcode.com/problems/rotating-the-box/

# Solution - 

class Solution:
    from collections import deque
    def transform(self, box):
        rotated = [list(list(i)[::-1]) for i in zip(*box)]
        return rotated
    
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        rotated = self.transform(box)
        rows = len(rotated)
        cols = len(rotated[0])
        #print(rotated)
        dq = deque()
        for j in range(cols):
            canBeFilled = None
            dq.clear()
            for i in range(rows-1, -1, -1):
                if rotated[i][j] == '#':
                    if canBeFilled != None:
                        rotated[canBeFilled][j] = '#'
                        rotated[i][j] = '.'
                        dq.popleft();
                        if dq:
                            canBeFilled = dq[0]
                            dq.append(i)
                        else:
                            dq.append(i)
                            canBeFilled = i
                elif rotated[i][j] == '*':
                    canBeFilled = None
                    dq.clear()
                else:
                    if canBeFilled == None:
                        canBeFilled = i
                    dq.append(i)
                    
        return rotated
