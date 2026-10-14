"""
Given an unsorted array containing numbers and a number ‘k’,
find the first ‘k’ missing positive numbers in the array.

Example 1:
Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.

Example 2:
Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6.

Example 3:
Input: [-2, -3, 4], k=2
Output: [1, 2]
Explanation: The smallest missing positive numbers are 1 and 2.
Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
1 <= k <= 1000
"""


def find_first_k(nums: list[int], k: int) -> list[int]:
    n = len(nums)
    i = 0
    # Phase 1: Rearrange elements to their correct positions
    while i < n:
        j = nums[i] - 1
        if 0 <= j < n and nums[i] != nums[j]:
            # Swap elements to their correct positions
            nums[i], nums[j] = nums[j], nums[i]
        else:
            i += 1

    missing_numbers: list[int] = []
    extra_numbers: set[int] = set()
    # Phase 2: Identify missing and extra numbers
    for j in range(n):
        if len(missing_numbers) >= k:
            break
        if nums[j] != j + 1:
            missing_numbers.append(j + 1)  # Track missing numbers
            extra_numbers.add(nums[j])  # Track extra numbers

    # Phase 3: Find remaining missing numbers
    candidate_number = n + 1
    while len(missing_numbers) < k:
        # Ignore if the array contains the candidate number
        if candidate_number not in extra_numbers:
            missing_numbers.append(candidate_number)
        candidate_number += 1
    return missing_numbers
