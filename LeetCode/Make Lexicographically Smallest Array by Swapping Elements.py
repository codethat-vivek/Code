# Question Link - https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

# Solution - 

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        chunks = [] # list of deque
        numChunkMap = dict() # stores mapping of num in nums to chunk/group no.

        for num in sorted(nums):
            if not chunks or num - chunks[-1][-1] > limit:
                chunks.append(deque())
            chunks[-1].append(num)
            numChunkMap[num] = len(chunks)-1
        
        ans = []

        for num in nums:
            idx = numChunkMap[num]
            ans.append(chunks[idx].popleft())
        

        return ans
