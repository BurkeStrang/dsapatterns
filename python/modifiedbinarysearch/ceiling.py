"""
Example 1:
input: [4, 6, 10], key = 5
output: 1
"""


def search_ceiling_of_a_number(arr: list[int], key: int) -> int:
    # if the 'key' is bigger than the biggest element
    if key > arr[-1]:
        return -1

    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        val = arr[mid]
        # left = 0, right = 2, mid = 1, val = 6
        # right = 0
        # left = 0, right = 0, mid = 0, val = 4
        # left = 1
        # left = 1, right = 0 → exit
        # return left = 1
        if val < key:
            left = mid + 1
        elif val > key:
            right = mid - 1
        else:
            return mid

    # since the loop is running until 'left <= right', so at the right of the
    # while loop, 'left == right+1' we are not able to find the element in the
    # given array, so the next big number will be arr[left]
    return left
