# Question Link - https://leetcode.com/problems/flatten-nested-list-iterator/

# Solution - 

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.flat = []
        self.it = 0
        
        def flatten(arr):
            for each in arr:
                if each.isInteger():
                    self.flat.append(each.getInteger())
                else:
                    flatten(each.getList())
        flatten(nestedList)
    
    def next(self) -> int:
        ans = self.flat[self.it]
        self.it += 1
        return ans
    
    def hasNext(self) -> bool:
        if self.it < len(self.flat):
            return True
        return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
