# Contest Link - https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-128/problems
# Solution - 

#User function Template for python3

class Solution:
    def findGoodPairs(self, a, n, k):
        # code here
        import collections
        from bisect import bisect_left
        ans = 0
        dt = collections.defaultdict(list)
        for i in range(n):
            dt[a[i]].append(i)

        for i in range(n):
            idx = bisect_left(dt[a[i]], i+k)
            ans += max(0, len(dt[a[i]])-idx)
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = map(int,input().split())
        a = list(map(int, input().split()))
        ob = Solution()
        ans = ob.findGoodPairs(a, n, k)
        print(ans)
        tc -= 1
# } Driver Code Ends
