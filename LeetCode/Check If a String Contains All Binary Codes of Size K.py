# Question Link - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

# Solution - 

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        st = set()
        i, j = 0, k-1
        while j < len(s):
            st.add(int(s[i:j+1]))
            i += 1
            j += 1
        
        if len(st) == 2**k:
            return True
        return False
