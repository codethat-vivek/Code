# Question Link - https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

# Solution - 

class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        if num % 3 != 0:
            return []
        return [num//3-1, num//3, num//3+1]
