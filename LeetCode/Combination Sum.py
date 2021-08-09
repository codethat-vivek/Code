# Question Link - https://leetcode.com/problems/combination-sum/

# Solution - 

class Solution:
    def helper(self, candidates, target):
        if target < 0:
            return []
        if target == 0:
            return [[]]
        ans = []
        for each in candidates:
            rem = target - each
            temp = self.helper(candidates, rem)
            if temp != []:
                for x in temp:
                    x.append(each)
                    ans.append(x)
        return ans
            
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        st = set()
        ans = []
        
        temp =  self.helper(candidates, target)
        for each in temp:
            each.sort()
            st.add(tuple(each))
        for each in st:
            ans.append(list(each))
        return ans
        
        
