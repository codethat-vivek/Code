# Question Link - https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

# Solution - 

class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        d = dict()
        n = len(nums)
        for each in nums:
            if each in d:
                d[each]+=1
            else:
                d[each] = 1
    
        l = [d[i] for i in sorted(d)]
        
        ans = 0
        last = 0
        
        l = l[-1:0:-1]
        #print(l)
        for i in l:
            ans += (i + last)
            last += i 
        return ans
