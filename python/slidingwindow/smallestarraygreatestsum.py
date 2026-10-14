"""
Given an array of positive integers and a number ‘S,’ find the length of the
smallest contiguous subarray whose sum is greater than or equal to 'S'.
Return 0 if no such subarray exists.

Example 1:
Input: arr = [2, 1, 5, 2, 3, 2], S=7
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to '7' is
[5, 2].

Example 2:
Input: arr = [2, 1, 5, 2, 8], S=7
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is
[8].

Example 3:
Input: arr = [3, 4, 1, 1, 6], S=8
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are
[3, 4, 1] or [1, 1, 6].
Constraints:

1 <= S <=
1 <= arr.length <= 105
1 <= arr[i] <= 104
"""

import math


def find_min_sub_array(s: int, arr: list[int]) -> int:
    window_sum = 0
    min_length = math.inf
    window_start = 0
    for window_end in range(len(arr)):
        window_sum += arr[window_end]  # add the next element
        # shrink the window as small as possible until the 'window_sum' is
        # smaller than 's'
        while window_sum >= s:
            min_length = min(min_length, window_end - window_start + 1)
            window_sum -= arr[window_start]  # subtract the element going out
            window_start += 1  # slide the window ahead
    if min_length == math.inf:
        return 0
    return int(min_length)
