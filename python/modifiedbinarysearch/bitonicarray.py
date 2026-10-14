"""
Given a Bitonic array, find if a given ‘key’ is present in it.
An array is considered bitonic if it is first monotonically increasing and
then monotonically decreasing.
In other words,
a bitonic array starts with a sequence of increasing elements,
reaches a peak element,
and then follows with a sequence of decreasing elements.
The peak element is the maximum value in the array.
Write a function to return the index of the ‘key’.
If the 'key' appears more than once, return the smaller index.
If the ‘key’ is not present, return -1.

Example 1:
Input: [1, 3, 8, 4, 3], key=4
Output: 3

Example 2:
Input: [3, 8, 3, 1], key=8
Output: 1

Example 3:
Input: [1, 3, 8, 12], key=12
Output: 3

Example 4:
Input: [10, 9, 8], key=10
Output: 0
"""


def find_max(arr: list[int]) -> int:
    start = 0
    end = len(arr) - 1
    while start < end:
        mid = start + (end - start) // 2
        if arr[mid] > arr[mid + 1]:
            end = mid
        else:
            start = mid + 1
    # at the end of the while loop, 'start == end'
    return start


def search_within(arr: list[int], key: int, start: int, end: int) -> int:
    """An order-agnostic binary search."""
    while start <= end:
        mid = start + (end - start) // 2
        if key == arr[mid]:
            return mid
        if arr[start] < arr[end]:
            # ascending order
            if key < arr[mid]:
                end = mid - 1
            else:
                start = mid + 1
        # descending order
        elif key > arr[mid]:
            end = mid - 1
        else:
            start = mid + 1
    return -1  # element is not found


def search_bitonic(arr: list[int], key: int) -> int:
    """Searches for a key in a bitonic array."""
    max_index = find_max(arr)
    key_index = search_within(arr, key, 0, max_index)
    if key_index != -1:
        return key_index
    return search_within(arr, key, max_index + 1, len(arr) - 1)
