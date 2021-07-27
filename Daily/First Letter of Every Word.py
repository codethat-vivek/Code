'''
Given a string S, the task is to create a string with the first letter of every word in the string.
Input: 
S = "bad is good"
Output: big
'''
#SOLUTION -

class Solution:
    def firstAlphabet(self, S):
        # code here
        ans = ""
        for each in S.split(" "):
            ans += each[0]
        return ans

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.firstAlphabet(S)
        
        print(answer)
