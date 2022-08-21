# Question Link - https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition

# Solution - 

class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        ans = 0
        idx = experience.index(max(experience))
        exp = 0
        while idx > 0:
            exp = max(exp, experience[idx]+1)
            exp -= experience[idx-1]
            idx -= 1
        if exp < experience[0] : exp = experience[0]+1
        #print(exp)
        
        s = sum(energy)
        if s+1 > initialEnergy:
            ans += (s+1-initialEnergy)
        
        if exp > initialExperience:
            ans += (exp-initialExperience)
        
        return ans
            
