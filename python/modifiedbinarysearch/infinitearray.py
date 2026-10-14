"""
Given an infinite sorted array (or an array with unknown size),
find if a given number ‘key’ is present in the array.
Write a function to return the index of the ‘key’ if it is present in the
array, otherwise return -1.
Since it is not possible to define an array with infinite (unknown) size,
you will be provided with an interface ArrayReader to read elements of the
array.
ArrayReader.get(index) will return the number at index;
if the array’s size is smaller than the index, it will return
Integer.MAX_VALUE.

Example 1:
Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
Output: 6
Explanation: The key is present at index '6' in the array.

Example 2:
Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
Output: -1
Explanation: The key is not present in the array.

Example 3:
Input: [1, 3, 8, 10, 15], key = 15
Output: 4
Explanation: The key is present at index '4' in the array.

Example 4:
Input: [1, 3, 8, 10, 15], key = 200
Output: -1
Explanation: The key is not present in the array.
"""

import sys


class ArrayReader:
    def __init__(self, values: list[int]) -> None:
        self.arr = values

    def get(self, index: int) -> int:
        """Returns the number at index, or sys.maxsize past the end of the
        array."""
        if index >= len(self.arr):
            return sys.maxsize
        return self.arr[index]


def binary_search(reader: ArrayReader, key: int, start: int, end: int) -> int:
    while start <= end:
        mid = start + (end - start) // 2
        val = reader.get(mid)
        if key < val:
            end = mid - 1
        elif key > val:
            start = mid + 1
        else:
            return mid  # found the key
    return -1


def search_infinite_sorted_array(reader: ArrayReader, key: int) -> int:
    # find the proper bounds first
    start = 0
    end = 1
    while reader.get(end) < key:
        new_start = end + 1
        end += (end - start + 1) * 2  # increase to double the bounds size
        start = new_start
    return binary_search(reader, key, start, end)
