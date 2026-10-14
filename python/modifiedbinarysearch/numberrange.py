"""
Given an array of numbers sorted in ascending order, find the range of a
given number ‘key’.
The range of the ‘key’ will be the first and last position of the ‘key’ in
the array.
Write a function to return the range of the ‘key’. If the ‘key’ is not
present return [-1, -1].

Example 1:
Input: [4, 6, 6, 6, 9], key = 6
Output: [1, 3]

Example 2:
Input: [1, 3, 8, 10, 15], key = 10
Output: [3, 3]

Example 3:
Input: [1, 3, 8, 10, 15], key = 12
Output: [-1, -1]
"""


def search(arr: list[int], key: int, find_max_index: bool) -> int:
    key_index = -1
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = start + (end - start) // 2
        if key < arr[mid]:
            end = mid - 1
        elif key > arr[mid]:
            start = mid + 1
        else:  # key == arr[mid]
            key_index = mid
            if find_max_index:
                start = mid + 1  # search ahead to find the last index of 'key'
            else:
                end = mid - 1  # search behind to find the first index of 'key'
    return key_index


def find_range(arr: list[int], key: int) -> list[int]:
    result = [-1, -1]
    result[0] = search(arr, key, False)
    # no need to search, if 'key' is not present in the input array
    if result[0] != -1:
        result[1] = search(arr, key, True)
    return result
