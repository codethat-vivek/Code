'''
Given an array and a target sum, you have to find distinct pairs with sum equal to target
For Ex:

Input -
n : 8
arr : 1, 1, 2, 3, 3, 4, 4, 5
target : 6

Output -
5

'''


# SOLUTION - 

def countPairs(arr, target):
  d = dict() # creating a dictionary that stores (value, frequency)
  n = len(arr)
  for i in range(n):
    if arr[i] in d:
      d[arr[i]] += 1
    else:
      d[arr[i]] = 1
  
  ans = 0
  for i in range(n):
    if target-arr[i] in d:
      ans += d[target-arr[i]]
      
    if target - arr[i] == arr[i]: #ensuring that pair (arr[i], arr[i]) is not considered
      ans -= 1

  return ans//2 # since every pair got counted twice
