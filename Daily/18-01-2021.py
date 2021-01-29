'''
Question -
  Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. 
  There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, 
  and he wants to maximize the number of toys he buys with this money. Given a list of toy prices and an amount to spend, 
  determine the maximum number of gifts he can buy.

Note: Each toy can be purchased only once.

Example:
prices = [1,2,3,4]
k = 7
The budget is 7 units of currency. He can buy items that cost [1,2,3] for 6, or [3,4] for 7 units. The maximum is 3 items.

Constraints:
1 <= n <= 10^5
1 <= k <= 10^9
1 <= prices[i] <= 10^9
A toy can't be bought multiple times.
'''

# SOLUTION -

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maximumToys function below.
def maximumToys(prices, k):
    prices.sort()
    cnt = 0
    for each in prices:
        if k > 0:
            k -= each
            cnt += 1
    return cnt - 1
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    prices = list(map(int, input().rstrip().split()))

    result = maximumToys(prices, k)

    fptr.write(str(result) + '\n')

    fptr.close()
