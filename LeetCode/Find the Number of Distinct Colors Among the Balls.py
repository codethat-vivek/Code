# Question Link - https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

# Solution - 

class HashMap:
    def __init__(self):
        self.dt = collections.defaultdict(set)
        self.size = 0
    def add(self, box, color, prevColor=-1):
            if prevColor != -1:
                self.dt[prevColor].remove(box)
                if len(self.dt[prevColor]) == 0:
                    self.size -= 1
            if len(self.dt[color]) == 0:
                self.size += 1
            self.dt[color].add(box)

    def getSize(self):
        return self.size


class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        dt, ans = dict(), []
        obj = HashMap()
        for box, color in queries:
            if box not in dt:
                obj.add(box, color)
            else:
                obj.add(box, color, dt[box])
        
            dt[box] = color
            ans.append(obj.getSize())
        
        return ans
