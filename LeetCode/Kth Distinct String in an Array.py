# Question Link - https://leetcode.com/problems/kth-distinct-string-in-an-array/

# Solution - 

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        from collections import Counter
        cnt = Counter(arr)
        for each in arr:
            if cnt[each] != 1 : continue
            k -= 1
            if k == 0:
                return each
        return ""
