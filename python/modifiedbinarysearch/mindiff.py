"""
Given an array of numbers sorted in ascending order,
find the element in the array that has the minimum difference with the given
‘key’.

Example 1:
Input: [4, 6, 10], key = 7
Output: 6
Explanation: The difference between the key '7' and '6' is minimum than any
other number in the array

Example 2:
Input: [4, 6, 10], key = 4
Output: 4

Example 3:
Input: [1, 3, 8, 10, 15], key = 12
Output: 10

Example 4:
Input: [4, 6, 10], key = 17
Output: 10
"""


def search_min_diff(arr: list[int], key: int) -> int:
    # smaller than the smallest element
    if key < arr[0]:
        return arr[0]
    # larger than the largest element
    if key > arr[-1]:
        return arr[-1]

    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = start + (end - start) // 2
        if key < arr[mid]:
            end = mid - 1
        elif key > arr[mid]:
            start = mid + 1
        else:
            return arr[mid]

    # at the end of the while loop, 'start == end+1'
    # we are not able to find the element in the given array
    # return the element which is closest to the 'key'
    if (arr[start] - key) < (key - arr[end]):
        return arr[start]
    return arr[end]
