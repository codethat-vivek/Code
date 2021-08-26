# Question Link - https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

# Solution - 

class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        preorder = preorder.split(",")
        counter = 1
        n = len(preorder)
        for i in range(n):
            counter -= 1
            if counter < 0:
                return False
            if preorder[i] != '#':
                counter += 2
        #print(counter)
        if counter == 0:
            return True
        return False
