// Given a sorted array and a target sum, find the indices of a pair of
// numbers that add up to the target. Returns None if there is no such pair.

// search returns the indices of the pair, or null if there is none.
export function search(
  arr: number[],
  targetSum: number,
): [number, number] | null {
  let left = 0;
  let right = arr.length - 1;
  while (left < right) {
    const sum = arr[left] + arr[right];
    if (sum === targetSum) {
      return [left, right];
    }
    if (sum < targetSum) {
      left++;
    } else {
      right--;
    }
  }
  return null;
}
