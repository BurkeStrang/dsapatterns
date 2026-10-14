"""
Given a set of positive numbers,
find if we can partition it into two subsets such that the sum of elements in
both subsets is equal.

Example 1:
Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into two subsets with equal
sum: {1, 4} & {2, 3}

Example 2:
Input: {1, 1, 3, 4, 7}
Output: True
Explanation: The given set can be partitioned into two subsets with equal
sum: {1, 3, 4} & {1, 7}

Example 3:
Input: {2, 3, 4, 6}
Output: False
Explanation: The given set cannot be partitioned into two subsets with equal
sum.
Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
"""


def can_partition(nums: list[int]) -> bool:
    """Bottom up dp."""
    n = len(nums)
    # find the total sum
    total = sum(nums)

    # if 'total' is an odd number, we can't have two subsets with the same
    # total
    if total % 2 != 0:
        return False

    # we are trying to find a subset of given numbers that has a total sum of
    # total/2.
    half = total // 2
    dp = [[False] * (half + 1) for _ in range(n)]

    # populate the sum=0 columns, as we can always form '0' sum with an empty
    # set
    for i in range(n):
        dp[i][0] = True

    # with only one number, we can form a subset only when the required sum
    # is equal to its value
    for s in range(1, half + 1):
        dp[0][s] = nums[0] == s

    # process all subsets for all sums
    for i in range(1, n):
        for s in range(1, half + 1):
            if dp[i - 1][s]:
                # if we can get the sum 's' without the number at index 'i'
                dp[i][s] = dp[i - 1][s]
            elif s >= nums[i]:
                # else we can find a subset to get the remaining sum
                dp[i][s] = dp[i - 1][s - nums[i]]

    # the bottom-right corner will have our answer.
    return dp[n - 1][half]
