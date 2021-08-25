# Question Link - https://leetcode.com/problems/sum-of-square-numbers/

# Solution - 

class Solution:
    # n = 2147483648
    def bs(self, arr, start, end, target):
        while start <= end:
            mid = start + (end - start)//2
            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                start = mid+1
            else:
                end = mid-1
        return -1
    def judgeSquareSum(self, c: int) -> bool:
        arr = []
        k = 0
        while k*k <= c:
            arr.append(k*k)
            k += 1
        l = len(arr)
        for each in arr:
            if self.bs(arr, 0, l-1, c-each) != -1:
                return True
        return False
