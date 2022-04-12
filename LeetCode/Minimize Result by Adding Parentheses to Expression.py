# Question Link - https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

# Solution - 

class Solution:
    def minimizeResult(self, expression: str) -> str:
        plus = expression.index("+")
        temp, value, ans = expression, eval(expression), expression
        for i in range(plus):
            firstPart = ""
            if i != 0: 
                firstPart = temp[:i] + '*(' + temp[i:plus+1]
            else: 
                firstPart = temp[:i] + '(' + temp[i:plus+1]

            for j in range(plus+1, len(temp)):
                secondPart = ""
                if j != len(temp)-1:
                    secondPart = temp[plus+1:j+1] + ')*' + temp[j+1:]
                else:
                    secondPart = temp[plus+1:j+1] + ')' + temp[j+1:]
   
                newExpression = firstPart + secondPart             
                t = eval(newExpression)
                if t <= value:
                    value = t
                    ans = newExpression.replace('*', '')
                
        
        return ans
