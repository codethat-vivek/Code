# Question Link - https://leetcode.com/problems/count-tested-devices-after-test-operations/

# Solution - 

class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        n = len(batteryPercentages)
        ans = 0
        for i in range(n):
            if batteryPercentages[i] > 0 : ans += 1
            if batteryPercentages[i] == 0: continue
            for j in range(i+1, n):
                batteryPercentages[j] = max(0, batteryPercentages[j]-1)
            #print(batteryPercentages)
        return ans
