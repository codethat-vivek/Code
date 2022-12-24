# Question Link - https://leetcode.com/problems/design-memory-allocator/

# Solution - 

class Allocator:

    def __init__(self, n: int):
        self.arr = [None for _ in range(n)]
        self.hash = collections.defaultdict(list)

    def allocate(self, size: int, mID: int) -> int:
        i, n = 0, len(self.arr)
        while i < n:
            x = i
            while i < n and self.arr[i] == None and i-x+1 <= size:
                i += 1
            if i-x+1 > size:
                for j in range(x, i):
                    self.hash[mID].append(j)
                    self.arr[j] = mID
                return x
            if x == i:
                i += 1
        return -1

    def free(self, mID: int) -> int:
        cnt = 0
        for idx in self.hash[mID]:
            self.arr[idx] = None
            cnt += 1
        self.hash[mID].clear()
        return cnt
