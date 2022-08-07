# Question Link - https://leetcode.com/problems/count-vowels-permutation/

# Solution - 

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        if n == 1 : return 5
        
        mod = int(1e9+7)
        
        allowed = dict()
        allowed['a'] = ['e']
        allowed['e'] = ['a', 'i']
        allowed['i'] = ['a', 'e', 'o', 'u']
        allowed['o'] = ['i', 'u']
        allowed['u'] = ['a']
        
        def calc(n, char, memo):
            if n == 1:
                return len(allowed[char])
            key = str(n) + str(char)
            if key in memo : return memo[key]
            res = 0
            for each in allowed[char]:
                res = (res+calc(n-1, each, memo))%mod
            memo[key] = res
            return res
    
        ans = 0
        for key in allowed.keys():
            x = calc(n-1, key, {})
            print(key, x)
            ans = (ans+x)%mod
        
        return ans
