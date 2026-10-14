"""
Given an array of integers arr, return the sum of the minimum values from all
possible contiguous subarrays within arr.
Since the result can be very large, return the final sum modulo (109 + 7).

Example 1:
Input: arr = [3, 1, 2, 4, 5]
Expected Output: 30
Explanation:
The subarrays are: [3], [1], [2], [4], [5], [3,1], [1,2], [2,4], [4,5],
[3,1,2], [1,2,4], [2,4,5], [3,1,2,4], [1, 2, 4, 5], [3, 1, 2, 4, 5].
The minimum values of these subarrays are: 3, 1, 2, 4, 5, 1, 1, 2, 4, 1, 1,
2, 1, 1, 1.
Summing these minimums: 3 + 1 + 2 + 4 + 5 + 1 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1
+ 1 = 30.

Example 2:
Input: arr = [2, 6, 5, 4]
Expected Output: 36
Explanation:
The subarrays are: [2], [6], [5], [4], [2,6], [6,5], [5,4], [2,6,5], [6,5,4],
[2,6,5,4].
The minimum values of these subarrays are: 2, 6, 5, 4, 2, 5, 4, 2, 4, 2.
Summing these minimums: 2 + 6 + 5 + 4 + 2 + 5 + 4 + 2 + 4 + 2 = 36.

Example 3:
Input: arr = [7, 3, 8]
Expected Output: 35
Explanation:
The subarrays are: [7], [3], [8], [7,3], [3,8], [7,3,8].
The minimum values of these subarrays are: 7, 3, 8, 3, 3, 3.
Summing these minimums: 7 + 3 + 8 + 3 + 3 + 3 = 27.

Constraints:
1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
"""

MOD = 1_000_000_007


def sum_subarray_mins(arr: list[int]) -> int:
    n = len(arr)
    result = 0  # Final sum of subarray minimums
    stack: list[int] = []

    # Iterate through the array plus one extra iteration for a sentinel.
    for current_index in range(n + 1):
        # If we reached the end, use 0 as a sentinel value; otherwise, use
        # the current element. It helps to process all remaining elements in
        # the stack.
        current_element = arr[current_index] if current_index < n else 0

        # Process elements in the stack while the current element is smaller
        # than the element at the top. Here, we maintain monotonic increasing
        # stack.
        while stack and arr[stack[-1]] > current_element:
            # Pop the index whose corresponding element is greater than
            # current_element.
            min_index = stack.pop()

            # Calculate the number of subarrays where arr[min_index] is the
            # minimum:
            # 'ending' is the count of subarrays ending at min_index; they can
            # start anywhere after the previous index on the stack, or from
            # the start of the array if the stack is empty,
            # and 'starting' is the count of subarrays starting at min_index
            # that can extend until current_index.
            ending = min_index - stack[-1] if stack else min_index + 1
            starting = current_index - min_index
            count_subarrays = ending * starting

            # Add the contribution of arr[min_index] for these subarrays to
            # the result.
            result = (result + arr[min_index] * count_subarrays) % MOD

        # Push the current index onto the stack for further processing.
        stack.append(current_index)

    return result
