'''
Time complexity - O(NlogN)
Space complexity - O(N)
'''

def quicksort1(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[-1]

    left, mid, right = [], [], []

    for x in arr:
        if x < pivot:
            left.append(x)
        elif x == pivot:
            mid.append(x)
        else:
            right.append(x)

    return quicksort(left) + mid + quicksort(right)

arr = [1, 4, 2, 6, 7, 9, 2, 5, 7, 2, 1, 1, 4, 692, 5, 0, -2, 93, 0, 0, 0, 1, 1, 2, 5, 2, 4, 7, 73, 57]
arr = quicksort1(arr)
print(arr)

# -------------------------------------------------------------------------------------------------------------




#--------------------------------------------------------------------------------------------------------------
'''
Time Complexity - O(NlogN)
Space Complexity - O(1)


'''
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quickSort2(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)


arr = [10, 7, 8, 9, 1, 5]
quickSort2(arr, 0, len(arr) - 1)
print(*arr)
