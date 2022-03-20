# Question Link - https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

# Solution - 

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        counter = collections.Counter()
        for i in range(len(tops)):
            counter[tops[i]] += 1
            counter[bottoms[i]] += 1
        
        ans = inf
        
        for each in counter.keys():
            if counter[each] >= len(tops):
                print(each)
                # it is a possible candidate
                found = True
                topRotation = bottomRotation = 0
                for i in range(len(tops)):
                    if tops[i] != each and bottoms[i] != each:
                        found = False
                        break
                    if tops[i] == each and bottoms[i] == each:
                        continue
                    if tops[i] == each:
                        bottomRotation += 1
                    if bottoms[i] == each:
                        topRotation += 1
                if not found:
                    continue
                print(topRotation, bottomRotation)
                ans = min(ans, topRotation, bottomRotation)
        
        if ans == inf:
            return -1
        return ans
        
