# Question Link - https://leetcode.com/problems/add-to-array-form-of-integer/

# Solution - 

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        return [c for c in str(int(''.join(str(x) for x in num)) + k)]
        
