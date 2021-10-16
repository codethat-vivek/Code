'''
Best Time Complexity - O(n*log n)
Worst Time Complexity - O(n*log n)
Space Complexity - O(n)
Stable - Yes
Online - No
'''


def mergeSort(a):
    if len(a) > 1:
        n = len(a)
        mid = n//2
        first, second = a[:mid], a[mid:]
        mergeSort(first)
        mergeSort(second)
        
        i = j = k = 0
        while i<len(first) and j<len(second):
            if first[i] < second[j]:
                a[k] = first[i]
                i += 1
            else:
                a[k] = second[j]
                j += 1
            k += 1
        while i<len(first):
            a[k] = first[i]
            k += 1
            i += 1
        while j<len(second):
            a[k] = second[j]
            k += 1
            j += 1


a = [4, 2, 5, 8, 7, 1, 10, 9, 6, 3]
mergeSort(a)
print(a)



