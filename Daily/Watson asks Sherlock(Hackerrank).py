'''
Question - 
  Watson asks Sherlock:
  Given a string S of N 0's and M 1's, how many unique permutations of this string start with 1?
  Help Sherlock by printing the answer modulo (10^9+7).

  Input Format:
  First line contains T, the number of test cases.
  Each test case consists of N and M separated by a space.

  Output Format:
  For each test case, print the answer modulo (10^9+7).
  
  Constraints:
  1 ≤ T ≤ 200
  1 ≤ N,M ≤ 1000
  
  Sample Input:
  2
  1 1
  2 3
  
  Sample Output:
  1
  6
  
'''

# SOLUTION - 

#!/bin/python3

import os
import sys
 
# sys.setrecursionlimit() method is used to set the maximum depth of the Python interpreter stack to the required limit. 
# This limit prevents any program from getting into infinite recursion.
sys.setrecursionlimit(10**8)

def fact(k):
    if k == 0:
        return 1
    else:
        return k*fact(k-1)

# Complete the solve function below.
def solve(n, m):
    ans = fact(n + m - 1)
    ans = ans // (fact(n)*fact(m-1))
    return ans % (10**9 +7)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())
    for t_itr in range(t):
        nm = input().split()

        n = int(nm[0])

        m = int(nm[1])

        result = solve(n, m)

        fptr.write(str(result) + '\n')

    fptr.close()
