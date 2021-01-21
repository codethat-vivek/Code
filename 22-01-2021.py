'''
Question - 
  Given two points P(a, b) and Q(c, d) in the coordinate plane, find the equation of the line passing through both the points.
  Example 1: 
    Input: P = (3, 2)
    Q = (2, 6)
    Output: 4x+1y=14
    Explaination: Using the formula to get line equation from two points we can get it.
  Example 2:
    Input: P = (3, 2)
    Q = (5, 7)
    Output: 5x-2y=11
    Explaination: If we use the formula to get line equation from two points we get this equation.
'''

# SOLUTION - 

class Solution:
    def getLine(self, a, b, c, d):
        # code here
        req = ""
        if c-a != 0:
            if a-c > 0:
                req = "+" + str(a-c)
            else:
                req = str(a-c)
            #(y-y1)*(c-a) = (x-x1)*(d-b)
            # y(c-a) -y1c+y1a = x(d-b) - x1*d + x1b
            ans = str(d-b) + "x" + req + "y" + "=" + str(a*d-a*b-b*c+b*a)
            return ans
        else:
            return "y = a"


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        a, b = [int(x) for x in input().split()]
        c, d = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.getLine(a, b, c, d))
