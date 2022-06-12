# Question Link - https://leetcode.com/problems/calculate-amount-paid-in-taxes/

# Solution - 

class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        
        arr = [brackets[0][0]]
        sm = arr[0]
        for i in range(1, len(brackets)):
            if sm > income:
                break
            arr.append(brackets[i][0]-brackets[i-1][0])
            sm += arr[-1]
        
        print(arr)
        ans = 0
        for i in range(len(arr)):
            if income - arr[i] < 0:
                ans += income*brackets[i][1]
            else:
                income -= arr[i]
                ans += arr[i]*brackets[i][1]
            print(ans, end=" ")
        
        return ans/100
