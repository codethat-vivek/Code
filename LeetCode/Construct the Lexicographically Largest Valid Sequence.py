# Question Link - https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

# Solution - 

class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        ans = [-1]*(2*n-1)
        used = set()
        
        def fill(idx):
            if idx >= len(ans):
                return True
            if ans[idx] != -1:
                return fill(idx+1)
                
            for num in range(n, 0, -1):
                if num in used: continue
                if num == 1:
                    ans[idx] = 1
                    used.add(num)
                    if not fill(idx+1):
                        used.remove(num)
                        ans[idx] = -1
                    else:
                        return True
                if idx + num < len(ans) and ans[idx+num] == -1:
                    ans[idx+num] = num
                    ans[idx] = num
                    used.add(num)
                    if not fill(idx+1):
                        ans[idx+num] = -1
                        ans[idx] = -1
                        used.remove(num)
                    else:
                        return True
            if ans[idx] == -1:
                return False
            return True
        
        fill(0)

        return ans
                     
