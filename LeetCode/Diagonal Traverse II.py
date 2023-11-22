# Question Link - https://leetcode.com/problems/diagonal-traverse-ii/

# Solution - 

class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        '''
        in diagonal order traversal the elements that come in one traversal have same value of i+j
        
        '''
        
        dt = collections.defaultdict(list)
        for i in range(len(nums)):
            for j in range(len(nums[i])-1, -1, -1):
                dt[i+j].append(nums[i][j])
                
        
        
        ans = []
        for e in sorted(dt):
            ans.extend(dt[e][::-1])
        return ans
        
