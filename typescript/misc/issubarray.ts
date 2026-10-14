// Given two arrays, find if the second one is a subarray of the first: its
// numbers appear in the first array next to each other and in the same order.

export function isSubarray(nums: number[], sub: number[]): boolean {
  for (let i = 0; i + sub.length <= nums.length; i++) {
    if (sub.every((value, j) => nums[i + j] === value)) {
      return true;
    }
  }
  return false;
}
