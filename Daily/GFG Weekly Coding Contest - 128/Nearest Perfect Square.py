# Contest Link - https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-128/problems
# Solution - 


class Solution:
    def nearestSquare(self, n : int) -> int:
        # code here
        import math
        x = math.sqrt(n)
        t = int(x)
        if x == t:return n
        if n - t*t < (t+1)*(t+1)-n:
            return t*t
        return (t+1)*(t+1)
        
            



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.nearestSquare(n)
        
        print(res)
        

# } Driver Code Ends
