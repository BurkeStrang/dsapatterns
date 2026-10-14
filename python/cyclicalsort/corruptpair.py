"""
We are given an unsorted array containing ‘n’ numbers taken from the range 1
to ‘n’.
The array originally contained all the numbers from 1 to ‘n’,
but due to a data error,
one of the numbers got duplicated which also resulted in one number going
missing.
Find both these numbers.

Example 1:
Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.

Example 2:
Input: [3, 1, 2, 3, 6, 4]
Output: [3, 5]
Explanation: '3' is duplicated and '5' is missing.
Constraints:

2 <= nums.length <=
1 <= nums[i] <=
"""


def find_corrupt(nums: list[int]) -> tuple[int, int] | None:
    """Returns the duplicated number and the missing number."""
    i = 0
    while i < len(nums):
        # If the current number is not in its correct position, swap it with
        # the number at its correct position.
        j = nums[i] - 1
        if nums[i] != nums[j]:
            nums[i], nums[j] = nums[j], nums[i]
        else:
            i += 1

    # Iterate through the array to find the first misplaced number.
    for k in range(len(nums)):
        if nums[k] != k + 1:
            return (nums[k], k + 1)

    # No number is out of place.
    return None
