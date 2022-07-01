# Question Link - https://leetcode.com/problems/maximum-units-on-a-truck/

# Solution - 

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda item : -item[1])
        total = 0
        print(boxTypes)
        for each in boxTypes:
            if truckSize > 0:
                numBoxesThatIcanPick = min(truckSize, each[0])
                truckSize -= numBoxesThatIcanPick
                total += numBoxesThatIcanPick*each[1]
            else:
                break
        return total
