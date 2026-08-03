# Question Link - https://leetcode.com/problems/widest-possible-fence/description/

# Solution - 

class Solution:
    def maximumWidth(self, planks: list[int]) -> int:
        dt, dt2 = Counter(planks), Counter()
        n = len(planks)
        keys = sorted(list(dt.keys()))
        for i in range(len(keys)):
            for j in range(i+1, len(keys)):
                if (keys[i] + keys[j]) not in dt2:
                    dt2[keys[i] + keys[j]] += min(dt[keys[i]], dt[keys[j]]) + dt[keys[i]+keys[j]]
                else:
                    dt2[keys[i] + keys[j]] += min(dt[keys[i]], dt[keys[j]])
        
        for key in dt:
            if key not in dt2:
                dt2[key] = dt[key]
        for key in keys:
            if dt2[2*key] > 0:
                dt2[2*key] += dt[key]//2
        return max(dt2.values())
