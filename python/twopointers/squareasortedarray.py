"""
Problem Statement
Given a sorted array, create a new array containing squares of all the
numbers of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]
Constraints:

1 <= arr.length <= 104
-104 <= arr[i] <= 104
arr is sorted in non-decreasing order.
"""


def make_squares(arr: list[int]) -> list[int]:
    n = len(arr)
    squares = [0] * n
    # The next free position in the output, filled from the highest down.
    highest_square_idx = n - 1
    # Two pointers for the input array.
    left = 0
    right = n - 1

    # Traverse the input array from both ends towards the center.
    while left <= right:
        left_square = arr[left] * arr[left]
        right_square = arr[right] * arr[right]

        # Compare the squared values and store the larger one in the output.
        if left_square > right_square:
            squares[highest_square_idx] = left_square
            left += 1  # Move the left pointer to the right.
        else:
            squares[highest_square_idx] = right_square
            right -= 1  # Move the right pointer to the left.
        highest_square_idx -= 1

    return squares
