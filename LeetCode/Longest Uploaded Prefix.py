# Question Link - https://leetcode.com/problems/longest-uploaded-prefix/

# Solution - 

class LUPrefix:

    def __init__(self, n: int):
        self.st = set()
        self.nn = n
        self.stack = []
        for i in range(n, 0, -1):
            self.stack.append(i)
        

    def upload(self, video: int) -> None:
        self.st.add(video)

    def longest(self) -> int:
        while len(self.stack) and self.stack[-1] in self.st:
            self.stack.pop()
        if not len(self.stack) : return self.nn 
        return self.stack[-1]-1


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
