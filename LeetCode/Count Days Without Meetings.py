# Question Link - https://leetcode.com/problems/count-days-without-meetings/description/

# Solution - 

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        arr = []
        for u, v in meetings:
            if len(arr) > 0 and arr[-1][1] >= u:
                arr[-1][1] = max(arr[-1][1], v)
            else:
                arr.append([u, v])
        

        ans, prev = 0, 0
        for u, v in arr:
            ans += max(0, u-prev-1)
            prev = v
        ans += days - prev

        return ans
