# Contest Link - https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-128/problems
# Solution -

#User function Template for python3

from typing import List

class Solution:
    def minimumTime(self, N : int, NUM : int, time : List[int]) -> int:
        
        def calc(m):
            x = 0
            for t in time:
                x += (m//t)
                if x >= NUM:
                    return x
            return x
        
        low, high = min(time)-1, NUM*min(time)+1 # 2, 400
        ans = high
        while low < high:
            mid = low + (high - low)//2 # 201, 101, 51, 76, 88, 
            x = calc(mid)
            if x >= NUM:
                ans = mid
                #print(ans, end= " ")
                high = mid-1
            elif x < NUM:
                low = mid+1
        x = calc(ans-1)
        if x >= NUM:
            return ans-1
        return ans
                



#{ 
 # Driver Code Starts
#Initial Template for Python 3


        

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        N,NUM=map(int,input().split())
        
        time=IntArray().Input(N)
        
        obj = Solution()
        res = obj.minimumTime(N, NUM, time)
        
        print(res)
# } Driver Code Ends
