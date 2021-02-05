'''
Question - Merge The Tools!
Consider the following:

A string, s, of length n.
An integer, k, where k is a factor of n.
We can split s into n/k substrings where each subtring, consists of a contiguous block of k characters in s. Then, use each substring to create string such that:

The characters in the substring are a subsequence of the characters in the substring.
Any repeat occurrence of a character is removed from the string such that each character in substring occurs exactly once.

Sample Input :
STDIN       Function
-----       --------
AABCAAADA   s = 'AABCAAADA'
3           k = 3

Sample Output :
AB
CA
AD

'''

# SOLUTION - 

def merge_the_tools(string, k):
    # your code goes here
    for i in range(0, len(string), k):
        s = string[i:i+k]
        l = []
        for i in s:
            if i not in l:
                l.append(i)
        print(''.join(l))
