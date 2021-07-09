'''
Question - (Hackerrank Problem)
  A student is taking a cryptography class and has found anagrams to be very useful. Two strings are anagrams of each other if the first string's letters 
  can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. 
  For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

The student decides on an encryption scheme that involves two large strings. The encryption is dependent on the minimum number of character deletions
required to make the two strings anagrams. Determine this number.

Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams.
Any characters can be deleted from either of the strings.

Constraints:
1 <= |a|, |b| <= 10^4
The strings a and b consist of lowercase English alphabetic letters, ascii[a-z].
'''

# SOLUTION -

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    l1 = [0]*26
    l2 = [0]*26
    for each in a:
        l1[ord(each)-97] += 1
    for each in b:
        l2[ord(each)-97] += 1
    
    cnt = 0

    for i in range(len(l1)):
        cnt += abs(l1[i] - l2[i])
    
    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
