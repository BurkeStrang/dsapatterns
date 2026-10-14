"""
Given an array of unsorted numbers, find all unique triplets in it that add
up to zero.

Examples
Example 1
Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
Explanation: There are four unique triplets whose sum is equal to zero.
Example 2
Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.
Constraints:

3 <= arr.length <= 3000
-105 <= arr[i] <= 105
"""


def search_pair(
    arr: list[int], target_sum: int, left: int, triplets: list[list[int]]
) -> None:
    right = len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target_sum:
            # found the triplet
            triplets.append([-target_sum, arr[left], arr[right]])
            left += 1
            right -= 1
            # skip same elements to avoid duplicate triplets
            while left < right and arr[left] == arr[left - 1]:
                left += 1
            while left < right and arr[right] == arr[right + 1]:
                right -= 1
        elif current_sum < target_sum:
            left += 1  # we need a pair with a bigger sum
        else:
            right -= 1  # we need a pair with a smaller sum


def search_triplets(arr: list[int]) -> list[list[int]]:
    arr.sort()
    triplets: list[list[int]] = []
    for i in range(len(arr) - 2):
        # skip same element to avoid duplicate triplets
        if i > 0 and arr[i] == arr[i - 1]:
            continue
        search_pair(arr, -arr[i], i + 1, triplets)
    return triplets
