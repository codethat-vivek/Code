# Question Link - https://leetcode.com/problems/widest-possible-fence/description/

# Solution - 

class Solution:
    def maximumWidth(self, planks: list[int]) -> int:
        dt, dt2 = Counter(planks), Counter()
        n = len(planks)
        keys = sorted(list(dt.keys()))
        # print(dt)
        for i in range(len(keys)):
            for j in range(i+1, len(keys)):
                if (keys[i] + keys[j]) not in dt2:
                    dt2[keys[i] + keys[j]] += min(dt[keys[i]], dt[keys[j]]) + dt[keys[i]+keys[j]]
                else:
                    dt2[keys[i] + keys[j]] += min(dt[keys[i]], dt[keys[j]])
                
        # print(dt2)
        
        for key in dt:
            if key not in dt2:
                dt2[key] = dt[key]
        finalDt = Counter(dt2)
        # keys = sorted(list(dt.keys()))
        for key in keys:
            if finalDt[2*key] > 0:
                finalDt[2*key] += dt[key]//2
        # print(finalDt)
        return max(finalDt.values())
