"""
We are given an array containing positive and negative numbers. Suppose the
array contains a number ‘M’ at a particular index.
Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is
negative move backwards ‘M’ indices.
You should assume that the array is circular which means two things:

If, while moving forward, we reach the end of the array, we will jump to the
first element to continue the movement.
If, while moving backward, we reach the beginning of the array, we will jump
to the last element to continue the movement.
Write a method to determine if the array has a cycle.
The cycle should have more than one element and should follow one direction
which means the cycle should not contain both forward and backward movements.

Example 1:

Input: [1, 2, -1, 2, 2]
Output: true
Explanation: The array has a cycle among indices: 0 -> 1 -> 3 -> 0
Example 2:

Input: [2, 2, -1, 2]
Output: true
Explanation: The array has a cycle among indices: 1 -> 3 -> 1
Example 3:

Input: [2, 1, -1, -2]
Output: false
Explanation: The array does not have any cycle.
Constraints:

1 <= nums.length <= 5000
`-1000 <= nums[i] <= 1000
nums[i] != 0
"""


def find_next_index(
    arr: list[int], is_forward: bool, current_index: int
) -> int:
    """Returns the index the number at current_index jumps to, or -1 if the
    jump changes direction or lands where it started."""
    direction = arr[current_index] >= 0
    if is_forward != direction:
        return -1  # change in direction, return -1

    # Python's % never returns a negative number, so this also wraps around
    # for negative jumps
    next_index = (current_index + arr[current_index]) % len(arr)

    # one element cycle, return -1
    if next_index == current_index:
        next_index = -1
    return next_index


def loop_exists(arr: list[int]) -> bool:
    for i in range(len(arr)):
        is_forward = arr[i] >= 0  # if we are moving forward or not
        slow = i
        fast = i

        # if slow or fast becomes '-1' this means we can't find cycle for this
        # number
        while True:
            # move one step for slow pointer
            slow = find_next_index(arr, is_forward, slow)
            # move one step for fast pointer
            fast = find_next_index(arr, is_forward, fast)
            if fast != -1:
                # move another step for fast pointer
                fast = find_next_index(arr, is_forward, fast)
            if slow == -1 or fast == -1 or slow == fast:
                break

        if slow != -1 and slow == fast:
            return True
    return False
