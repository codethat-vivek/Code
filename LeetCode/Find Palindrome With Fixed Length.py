# Question Link - https://leetcode.com/problems/find-palindrome-with-fixed-length/

# Solution - 

class Solution:
    '''
    [101,111,121,131,141,...] intLength = 3 {TOTAL = 90}
    [1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991, 2002, 2112, 2222, 2332, 2442, 2552, 2662, ....., 9999] {TOTAL = 90}
    [10001, 10101, 10201, 10301, 10401, ..., 10901, 11011, 11111, 11211, ...., 11911, 12021, 12121, .... ] {TOTAL = 900}
    '''
    
    def generate(self, n, k): # n length ka kth number
        diff, t = None, math.ceil(n/2)
        minimum = int('1'+(t-1)*'0')
        maximum = int('9'*(t))
        diff = maximum - minimum + 1
        
        if k > diff:
            return -1
        
        ans = str(minimum + k - 1)
        if n % 2 == 0:
            return ans + ans[::-1]
        
        return ans + ans[:-1][::-1]
        
    
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        resultArray = []
        for i in range(len(queries)):
            resultArray.append(self.generate(intLength, queries[i]))
        
        return resultArray
