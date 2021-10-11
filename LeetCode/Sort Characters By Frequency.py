# Question Link - https://leetcode.com/problems/sort-characters-by-frequency/

# Solution - 

class Solution:
    def frequencySort(self, s: str) -> str:
        dt = dict()
        for each in s:
            if each not in dt:
                dt[each] = 1
            else:
                dt[each] += 1
        arr = []
        for i in dt:
            arr.append([i, dt[i]])
        arr.sort(key = lambda x : x[1], reverse = True)
        ans = ""
        for each in arr:
            ans += (each[0]*each[1])
        return ans
