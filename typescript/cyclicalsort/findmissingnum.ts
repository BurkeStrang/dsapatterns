// We are given an array containing n distinct numbers taken from the range 0 to
// n.
// Since the array has only n numbers out of the total n+1 numbers, find the
// missing number.
//
// Example 1:
// Input: [4, 0, 3, 1]
// Output: 2
//
// Example 2:
// Input: [8, 3, 5, 2, 4, 6, 0, 1]
// Output: 7
//
// Constraints:
// n == nums.length
// 1 <= n <=
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

export function findMissingNumber(nums: number[]): number {
  const n = nums.length;
  let i = 0;
  while (i < n) {
    const j = nums[i];
    if (j < n && nums[i] !== nums[j]) {
      [nums[i], nums[j]] = [nums[j], nums[i]];
    } else {
      i++;
    }
  }

  // Find the first number missing from its index, that will be our required
  // number
  for (let j = 0; j < n; j++) {
    if (nums[j] !== j) {
      return j;
    }
  }
  return n;
}
