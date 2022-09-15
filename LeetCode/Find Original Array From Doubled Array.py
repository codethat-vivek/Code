# Question Link - https://leetcode.com/problems/find-original-array-from-doubled-array/

# Solution - 

class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        
        ans = []
        changed.sort()
        
        count = collections.Counter(changed)
        
        for num in changed:
            if count[num] == 0 : continue
            if count[2*num] < 1 : return []
            count[num] -= 1
            count[2*num] -= 1
            if num == 0 and count[num] < 0 : return []
            ans.append(num)
        return ans
        
