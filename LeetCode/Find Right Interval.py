# Question Link - https://leetcode.com/problems/find-right-interval/

# Solution - 

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        dt = dict()
        for i in range(len(intervals)):
            dt[tuple(intervals[i])] = i     
        
        inter = sorted(intervals)
        
        ans = []
        for each in intervals:
            item = [each[1], -10**7]
            idx = bisect.bisect_left(inter, item)
            if idx == len(inter):
                ans.append(-1)
            else:
                ans.append(dt[tuple(inter[idx])])
        return ans
