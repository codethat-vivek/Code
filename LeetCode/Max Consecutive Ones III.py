# Question Link - https://leetcode.com/problems/max-consecutive-ones-iii/

# Solution - 

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n, i, j = len(nums), 0, 0
        cnt = best = 0
        temp = k
        while j<n:
            if nums[j] == 1:
                j += 1
                cnt += 1
            else:
                if temp > 0:
                    temp -= 1
                    cnt += 1
                elif temp == 0:
                    best = max(best, cnt)
                    while nums[i] == 1:
                        i += 1
                        cnt -= 1
                    i += 1
                j += 1
            #print(i, j, cnt, best)
        
        best = max(best, cnt)
        return best
                    
            
