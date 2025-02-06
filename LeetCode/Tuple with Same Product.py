# Question Link - https://leetcode.com/problems/tuple-with-same-product/

# Solution - 

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        dt = collections.defaultdict(int)
        for i in range(n):
            for j in range(i+1, n):
                dt[nums[i]*nums[j]] += 1
        
        #print(dt)
        ans = 0
        for k in dt:
            v = dt[k]
            if v > 1:
                ans += (((v*(v-1))//2)*8)
        
        return ans
