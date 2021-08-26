# Question Link - https://leetcode.com/problems/next-greater-element-iii/

# Solution - 

class Solution:
    def nextPermutation(self, arr):
        pos = None
        n = len(arr)
        for i in range(n-1, 0, -1):
            if arr[i] > arr[i-1]:
                pos = i-1
                break
        if pos == None:
            return [-1]
        anotherPos = None
        for i in range(n-1, -1, -1):
            if arr[i] > arr[pos]:
                anotherPos = i
                break
        arr[pos], arr[anotherPos] = arr[anotherPos], arr[pos]
        arr = arr[:pos+1] + arr[pos+1:][::-1]
        return arr
        
    def nextGreaterElement(self, n: int) -> int:      
        s = str(n)
        arr = []
        for each in s:
            arr.append(int(each))
        
        t = self.nextPermutation(arr)
        
        if t == [-1]:
            return -1
        s = ""
        for each in t:
            s += str(each)
        n = int(s)
        if n > 2147483647:
            return -1
        return n
