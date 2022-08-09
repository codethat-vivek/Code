# Question Link - https://leetcode.com/problems/binary-trees-with-factors/

# Solution - 

class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        mod = int(1e9+7)
        dp = dict()
        def getFactors(n):
            lst = []
            for i in range(2, int(sqrt(n))+1):
                if n % i == 0 : 
                    if (n//i) != i : lst.append(n//i)
                    lst.append(i)
            return lst
        def helper(ele):
            factors = getFactors(ele)
            if len(factors) == 0:
                dp[ele] = 1
                return 1
            if ele in dp : return dp[ele]
            cnt = 1
            done = dict()
            for f in factors:
                first, second = f, ele//f
                if first not in done:
                    if first in dp and second in dp :
                        done[first] = 1
                        done[second] = 1
                        if first != second:
                            cnt = (cnt+2*dp[first]*dp[second])%mod
                        else:
                            cnt = (cnt+dp[first]*dp[second])%mod
            dp[ele] = cnt
            return cnt
        
        arr.sort()
        ans = 0
        for each in arr:
            ans = (ans+helper(each))%mod
        return ans
