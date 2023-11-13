# Contest Link - https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-128/problems
# Solution - 

class Solution:
    #Function to find element with more appearances between two elements in an array.    
    def majorityWins(self, arr, n, x, y):
        # code here
        cntx, cnty = 0, 0
        for e in arr:
            if e == x: cntx += 1
            if e == y: cnty += 1
        
        if cntx > cnty:
            return x
        elif cnty > cntx:
            return y
        return min(x, y)
    

if __name__ == '__main__':
    T=int(input())
    while(T>0):
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        
        x,y=map(int,input().strip().split())
        
        print(Solution().majorityWins(arr,n,x,y))
        T-=1
