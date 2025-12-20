# Question Link - https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/description/

# Solution - 

class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        nums.sort(reverse = True)
        arr, dt = [], collections.defaultdict(list)
        for i in range(len(nums)):
            if len(dt[nums[i]%3]) < 3:
                dt[nums[i]%3].append(nums[i])
        
        # 0 - [.....]
        # 1 - [.....]
        # 2 - [.....]

        # print(dt)

        values = [0]
        if len(dt[0]) == 3:
            values.append(sum(dt[0]))
        if len(dt[1]) == 3:
            values.append(sum(dt[1]))
        if len(dt[2]) == 3:
            values.append(sum(dt[2]))

        if len(dt[0]) > 0 and len(dt[1]) > 0 and len(dt[2]) > 0:
            values.append(dt[0][0] + dt[1][0] + dt[2][0])
        
        return max(values)
