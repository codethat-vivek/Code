# Question Link - https://leetcode.com/problems/3sum-with-multiplicity/

# Solution - 

class Solution:
    def threeSumMulti(self, nums: List[int], target: int) -> int:
        ans, inf = 0, int(1e9+7)
        nums.sort()
        count = collections.Counter(nums)
        dt = dict() # <int, list>... list = [first Index, last Index]
        for i in range(len(nums)):
            if nums[i] not in dt:
                dt[nums[i]] = [i, i]
            else:
                dt[nums[i]][1] = i        
        
        i=0
        while i < len(nums):
            newTarget = target - nums[i]
            j, k = i+1, len(nums)-1
            while j < k:
                sm = nums[j] + nums[k]
                if sm < newTarget:
                    j = dt[nums[j]][1]+1
                elif sm > newTarget:
                    k = dt[nums[k]][0]-1
                else:
                    a, b, c = count[nums[i]], count[nums[j]], count[nums[k]]
                    if nums[i] != nums[j] and nums[j] != nums[k]:
                        ans += (a*b*c)%inf
                    elif nums[i] == nums[j] and nums[j] != nums[k]:
                        ans += ((a*(a-1)//2)*c)%inf
                    elif nums[i] != nums[j] and nums[j] == nums[k]:
                        ans += ( a * (b*(b-1))//2 ) % inf
                    elif nums[i] == nums[j] == nums[k]:
                        ans += ((a*(a-1)*(a-2))//6) % inf
                    #print(ans)
                    j = dt[nums[j]][1]+1
                    k = dt[nums[k]][0]-1
                    
            i = dt[nums[i]][1]+1
            
        return ans    
        
