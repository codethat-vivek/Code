# Question Link - https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/description/

# Solution - 

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        dt = collections.Counter(nums)
        x = 0
        st = set()
        for key in dt:
            if dt[key] > 1:
                x += 1
                st.add(key)
        n = len(nums)
        m = len(dt)
        if n == m:
            return ans
        
        # print(dt)
        # print(st)
        # print(n, m, x)

        for i in range(0, len(nums)-3, 3):
            ans += 1
            dt[nums[i]] -= 1
            if dt[nums[i]] == 1 and nums[i] in st:
                x -= 1
            dt[nums[i+1]] -= 1
            if dt[nums[i+1]] == 1 and nums[i+1] in st:
                x -= 1
            dt[nums[i+2]] -= 1
            if dt[nums[i+2]] == 1 and nums[i+2] in st:
                x -= 1
            
            # print('x ', x, " ans", ans)

            if x <= 0:
                return ans

        return ans + 1


