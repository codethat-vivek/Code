// Question Link - https://leetcode.com/problems/longest-increasing-subsequence/

// Solution -

// O(nlogn)
class Solution:
    def binary_search(self, arr, target, low):
        high = len(arr)-1
        while low <= high:
            mid = (low+high)//2
            if arr[mid] < target:
                low = mid + 1
            elif arr[mid] > target:
                high = mid-1
            else:
                return mid
        return low
    
    def lengthOfLIS(self, arr: List[int]) -> int:
        myList = []
        myList.append(arr[0])
        for i in range(1, len(arr)):
            if myList[-1] < arr[i]:
                myList.append(arr[i])
            elif myList[-1] > arr[i]:
                idx = self.binary_search(myList, arr[i], 0)
                myList[idx] = arr[i]
            else:
                continue
        return len(myList)

/*
// O(n^2)
class Solution:
    def lengthOfLIS(self, arr: List[int]) -> int:
        n = len(arr)
        myList = [1 for _ in range(n)]
        for i in range(1, n):
            for j in range(i-1, -1, -1):
                if arr[j] < arr[i]:
                    myList[i] = max(myList[i], myList[j] + 1)

        ans = 0
        for i in range(n):
            if ans < myList[i]:
                ans = myList[i]

        return ans
*/
