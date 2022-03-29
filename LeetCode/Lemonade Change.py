# Question Link - https://leetcode.com/problems/lemonade-change/

# Solution - 

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        if bills[0] != 5:
            return False
        
        dt = collections.Counter()
        for each in bills:
            if each == 5:
                dt[each] += 1
            elif each == 10:
                if dt[5] == 0:
                    return False
                dt[5] -= 1
                dt[10] += 1
            else:
                if dt[5] == 0:
                    return False
                if dt[10] == 0 and dt[5] < 3:
                    return False
                if dt[10] >= 1:
                    dt[10] -= 1
                    dt[5] -= 1
                else:
                    dt[5] -= 3
        return True
