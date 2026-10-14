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

export function minMoves(nums: number[]): number {
  const n = nums.length;
  let minIndex = 0;
  let maxIndex = 0;

  // Find the indexes of the minimum and maximum elements
  for (let i = 0; i < n; i++) {
    if (nums[i] < nums[minIndex]) {
      minIndex = i;
    }
    if (nums[i] > nums[maxIndex]) {
      maxIndex = i;
    }
  }

  // Calculate distances from both ends
  const minDistStart = minIndex + 1;
  const minDistEnd = n - minIndex;
  const maxDistStart = maxIndex + 1;
  const maxDistEnd = n - maxIndex;

  // Determine the most efficient sequence of moves: take both from the
  // start, both from the end, or one from each end
  const bothFromStart = Math.max(minDistStart, maxDistStart);
  const bothFromEnd = Math.max(minDistEnd, maxDistEnd);
  const oneFromEachEnd = Math.min(
    minDistStart + maxDistEnd,
    minDistEnd + maxDistStart,
  );
  return Math.min(bothFromStart, bothFromEnd, oneFromEachEnd);
}
