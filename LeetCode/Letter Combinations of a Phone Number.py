# Question Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

# Solution - 

class Solution:
    def helper(self, dt, n, digits):
        if n == 1:
            return dt[int(digits[0])]
        prev = self.helper(dt, n-1, digits[1:])
        #print(prev)
        ans = []
        
        for i in dt[int(digits[0])]:
            for j in prev:
                ans.append(i+j)
        return ans

            
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        dt = dict()
        dt[2] = ["a", "b", "c"]
        dt[3] = ["d", "e", "f"]
        dt[4] = ["g", "h", "i"]
        dt[5] = ["j", "k", "l"]
        dt[6] = ["m", "n", "o"]
        dt[7] = ["p", "q", "r", "s"]
        dt[8] = ["t", "u", "v"]
        dt[9] = ["w", "x", "y", "z"]
        
        return self.helper(dt, len(digits), digits)
        
