# Question Link - https://leetcode.com/problems/partition-labels/

# Solution - 

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(set(s))
        dt = dict()
        # calculate first and last occurence of every character in s
        for i in range(len(s)):
            if s[i] not in dt:
                dt[s[i]] = [i]
            else:
                if len(dt[s[i]]) == 2:
                    dt[s[i]][1] = i
                else:
                    dt[s[i]].append(i)
        x = list(dt.values())
        x.sort(key = lambda m : m[0]) # sorting x on the basis of x[0]
        ans = []        
        start = end = x[0][0]
        if len(x[0]) > 1 : end = x[0][1]
        for i in range(1, len(x)):
            if start < x[i][0] < end:
                if len(x[i]) > 1 : end = max(end, x[i][1])
            else:
                ans.append(end-start+1)
                start = end = x[i][0]
                if len(x[i]) > 1 : end = x[i][1]
        ans.append(end-start+1)
        return ans
