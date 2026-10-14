"""
Given an array arr of unsorted numbers and a target sum, count all triplets
in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k
are three different indices. Write a function to return the count of such
triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1,
0, 3], [-1, 0, 2]
Example 2:

Input: [-1, 4, 2, 1, 3], target=5
Output: 4
Explanation: There are four triplets whose sum is less than the target:
[-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
Constraints:

n == arr.length
0 <= n <= 3500
-100 <= arr[i] <= 100
-100 <= target <= 100
"""


def get_pair(arr: list[int], target_sum: int, first: int) -> int:
    count = 0
    left = first + 1
    right = len(arr) - 1
    while left < right:
        if arr[left] + arr[right] < target_sum:
            # found the triplet
            # since arr[right] >= arr[left], therefore, we can replace
            # arr[right] by any number between left and right to get a sum
            # less than the target sum
            count += right - left
            left += 1
        else:
            right -= 1  # we need a pair with a smaller sum
    return count


def find_triplets(arr: list[int], target: int) -> int:
    arr.sort()
    count = 0
    for i in range(len(arr) - 2):
        count += get_pair(arr, target - arr[i], i)
    return count
