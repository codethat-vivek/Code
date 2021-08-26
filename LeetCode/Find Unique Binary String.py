# Question Link - https://leetcode.com/problems/find-unique-binary-string/

# Solution - 

class Solution:
    # def binToDec(self, n): # n -> str
    #     return int(n, 2)
    def decToBin(self, n): # n -> int
        return bin(n)[2:]
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        nums.sort()
        for i in range(n):
            temp = self.decToBin(i)
            l = len(temp)
            temp = "0"*(n-l) + temp
            if temp != nums[i]:
                return temp
        temp = self.decToBin(n)
        l = len(temp)
        temp = temp = "0"*(n-l) + temp
        return temp
