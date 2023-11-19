# Question Link - https://www.codingninjas.com/studio/problems/count-inversions_615

# Solution - 

from os import *
from sys import *
from collections import *
from typing import List
import math

def merge(arr : List[int], low : int, mid : int, high : int) -> int:
    temp = []   # temporary array
    left = low  # starting index of left half of arr
    right = mid + 1 # starting index of right half of arr

    cnt = 0     # Modification 1: cnt variable to count the pairs

    # storing elements in the temporary array in a sorted manner
    while (left <= mid and right <= high):
        if (arr[left] <= arr[right]):
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            cnt += (mid - left + 1)  # Modification 2
            right += 1

    # if elements on the left half are still left
    while (left <= mid):
        temp.append(arr[left])
        left += 1

    # if elements on the right half are still left
    while (right <= high):
        temp.append(arr[right])
        right += 1

    # transfering all elements from temporary to arr
    for i in range(low, high + 1):
        arr[i] = temp[i - low]

    return cnt   # Modification 3

def mergeSort(arr : List[int], low : int, high : int) -> int:
    cnt = 0
    if low >= high:
        return cnt
    mid = math.floor((low + high) / 2)
    cnt += mergeSort(arr, low, mid)    # left half
    cnt += mergeSort(arr, mid + 1, high)  # right half
    cnt += merge(arr, low, mid, high)  # merging sorted halves
    return cnt

def getInversions(arr, n) :
	# Write your code here.
	return mergeSort(arr, 0, n-1)

# Taking inpit using fast I/O.
def takeInput() :
    n = int(input())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

# Main.
arr, n = takeInput()
print(getInversions(arr, n))
