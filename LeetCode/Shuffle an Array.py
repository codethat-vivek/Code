# Question Link - https://leetcode.com/problems/shuffle-an-array/

# Solution - 

rom random import randint as r
from random import shuffle as s
from numpy import array
class Solution:
    def __init__(self, nums: List[int]):
        self.arr = nums
        self.fixed = array(nums).copy().tolist()

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.fixed
        

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        s(self.arr)
        return self.arr
        
