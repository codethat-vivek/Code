# Question Link - https://leetcode.com/problems/baseball-game/

# Solution - 

class Solution:
    def calPoints(self, ops: List[str]) -> int:
        arr = []
        for each in ops:
            if each == "C":
                arr.pop()
            elif each == "D":
                arr.append(2*arr[-1])
            elif each == "+":
                arr.append(arr[-1] + arr[-2])
            else:
                arr.append(int(each))
            
        return sum(arr)
