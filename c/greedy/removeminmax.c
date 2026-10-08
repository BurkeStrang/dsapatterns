// Determine the minimum number of deletions required to remove
// the smallest and the largest elements from an array of integers.
// In each deletion,
// you are allowed to remove either the first (leftmost) or the last (rightmost)
// element of the array.
//
// Example 1:
// Input: [3, 2, 5, 1, 4]
// Expected Output: 3
// Justification: The smallest element is 1 and the largest is 5. Removing 4, 1,
// and then 5
// (or 5, 4, and then 1) in three moves is the most efficient strategy.
//
// Example 2:
// Input: [7, 5, 6, 8, 1]
// Expected Output: 2
// Justification: Here, 1 is the smallest, and 8 is the largest. Removing 1 and
// then 8 in two moves is the optimal strategy.
//
// Example 3:
// Input: [2, 4, 10, 1, 3, 5]
// Expected Output: 4
// Justification: The smallest is 1 and the largest is 10. One strategy is to
// remove 2, 4, 10, and then 1 in four moves.
//
// Constraints:
// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// The integers in nums are distinct.

int min_of
(
    int a,
    int b
)
{
    return a < b ? a : b;
}

int max_of
(
    int a,
    int b
)
{
    return a > b ? a : b;
}

int min_moves
(
    const int *nums,
    int n
)
{
    int min_index = 0;
    int max_index = 0;
    int min_val = nums[0];
    int max_val = nums[0];

    // Find the indexes of the minimum and maximum elements
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < min_val)
        {
            min_index = i;
            min_val = nums[i];
        }
        if (nums[i] > max_val)
        {
            max_index = i;
            max_val = nums[i];
        }
    }

    // Calculate distances from both ends
    int min_dist_start = min_index + 1;
    int min_dist_end = n - min_index;
    int max_dist_start = max_index + 1;
    int max_dist_end = n - max_index;

    // Determine the most efficient sequence of moves
    int total_moves = min_of(max_of(min_dist_start, max_dist_start),
                             min_of(min_of(min_dist_start + max_dist_end,
                                           min_dist_end + max_dist_start),
                                    max_of(min_dist_end, max_dist_end)));

    return total_moves;
}
