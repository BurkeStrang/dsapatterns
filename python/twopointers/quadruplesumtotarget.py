"""
Given an array of unsorted numbers and a target number,
find all unique quadruplets in it, whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
"""


def search_pairs(
    arr: list[int],
    target_sum: int,
    first: int,
    second: int,
    quadruplets: list[list[int]],
) -> None:
    left = second + 1
    right = len(arr) - 1
    while left < right:
        current_sum = arr[first] + arr[second] + arr[left] + arr[right]
        if current_sum == target_sum:
            # found the quadruplet
            quadruplets.append([arr[first], arr[second], arr[left], arr[right]])
            left += 1
            right -= 1
            # skip same elements to avoid duplicate quadruplets
            while left < right and arr[left] == arr[left - 1]:
                left += 1
            while left < right and arr[right] == arr[right + 1]:
                right -= 1
        elif current_sum < target_sum:
            left += 1  # we need a pair with a bigger sum
        else:
            right -= 1  # we need a pair with a smaller sum


def search_quadruplets(arr: list[int], target: int) -> list[list[int]]:
    arr.sort()
    quadruplets: list[list[int]] = []
    for i in range(len(arr) - 3):
        # skip same element to avoid duplicate quadruplets
        if i > 0 and arr[i] == arr[i - 1]:
            continue
        for j in range(i + 1, len(arr) - 2):
            # skip same element to avoid duplicate quadruplets
            if j > i + 1 and arr[j] == arr[j - 1]:
                continue
            search_pairs(arr, target, i, j, quadruplets)
    return quadruplets
