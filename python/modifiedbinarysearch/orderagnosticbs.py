"""
Given a sorted array of numbers, find if a given number 'key' is present in
the array. Though we know that the array is sorted, we don't know if it's
sorted in ascending or descending order. You should assume that the array
can have duplicates.

Write a function to return the index of the 'key' if it is present in the
array, otherwise return -1.
"""


def desc_or_asc_search(arr: list[int], key: int) -> int:
    left = 0
    right = len(arr) - 1
    is_asc = arr[left] < arr[right]
    while left <= right:
        # calculate the middle of the current range
        mid = left + (right - left) // 2
        if key == arr[mid]:
            return mid
        if is_asc:
            # ascending order
            if key < arr[mid]:
                right = mid - 1  # the 'key' can be in the first half
            else:
                left = mid + 1  # the 'key' can be in the second half
        # descending order
        elif key > arr[mid]:
            right = mid - 1  # the 'key' can be in the first half
        else:
            left = mid + 1  # the 'key' can be in the second half
    return -1  # element not found
