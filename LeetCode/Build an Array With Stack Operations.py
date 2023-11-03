# Question Link - https://leetcode.com/problems/build-an-array-with-stack-operations/

# Solution - 

class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        i, j = 0, 1
        ans = []
        while i < len(target):
            if target[i] == j:
                ans.append("Push")
                i += 1
            else:
                ans.append("Push")
                ans.append("Pop")
            j += 1
        
        return ans
