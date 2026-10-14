"""
How do we search in a sorted and rotated array that also has duplicates?
The code above will fail in the following example!

Example 1:
Input: [3, 7, 3, 3, 3], key = 7
Output: 1
Explanation: '7' is present in the array at index '1'.
"""


def search_rotated_dups(arr: list[int], key: int) -> int:
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = start + (end - start) // 2
        if arr[mid] == key:
            return mid

        if arr[start] == arr[mid] and arr[end] == arr[mid]:
            # the only difference from the previous solution,
            # if numbers at indexes start, mid, and end are same, we can't
            # choose a side the best we can do, is to skip one number from
            # both ends as key != arr[mid]
            start += 1
            end -= 1
        elif arr[start] <= arr[mid]:
            # left side is sorted in ascending order
            if arr[start] <= key < arr[mid]:
                end = mid - 1
            else:
                start = mid + 1
        # right side is sorted in ascending order
        elif arr[mid] < key <= arr[end]:
            start = mid + 1
        else:
            end = mid - 1

    # we are not able to find the element in the given array
    return -1
