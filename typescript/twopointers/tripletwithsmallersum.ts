// Given an array arr of unsorted numbers and a target sum, count all triplets
// in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k
// are three different indices. Write a function to return the count of such
// triplets.
//
// Example 1:
//
// Input: [-1, 0, 2, 3], target=3
// Output: 2
// Explanation: There are two triplets whose sum is less than the target: [-1,
// 0, 3], [-1, 0, 2]
// Example 2:
//
// Input: [-1, 4, 2, 1, 3], target=5
// Output: 4
// Explanation: There are four triplets whose sum is less than the target:
// [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
// Constraints:
//
// n == arr.length
// 0 <= n <= 3500
// -100 <= arr[i] <= 100
// -100 <= target <= 100

export function getPair(
  arr: number[],
  targetSum: number,
  first: number,
): number {
  let count = 0;
  let left = first + 1;
  let right = arr.length - 1;
  while (left < right) {
    if (arr[left] + arr[right] < targetSum) {
      // found the triplet
      // since arr[right] >= arr[left], therefore, we can replace arr[right]
      // by any number between left and right to get a sum less than the
      // target sum
      count += right - left;
      left++;
    } else {
      right--; // we need a pair with a smaller sum
    }
  }
  return count;
}

export function findTriplets(arr: number[], target: number): number {
  arr.sort((a, b) => a - b);
  let count = 0;
  for (let i = 0; i < arr.length - 2; i++) {
    count += getPair(arr, target - arr[i], i);
  }
  return count;
}
