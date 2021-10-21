# Question Link - https://leetcode.com/problems/insert-delete-getrandom-o1/

# Solution - 

class RandomizedSet:
    
    def __init__(self):
        self.st = set()

    def insert(self, val: int) -> bool:
        if val in self.st: 
            return False
        self.st.add(val)
        return True

    def remove(self, val: int) -> bool:
        if val in self.st: 
            self.st.remove(val)
            return True
        return False

    def getRandom(self) -> int:
        from random import choice
        return choice(list(self.st))


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
