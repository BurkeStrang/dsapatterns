// Given an array of positive numbers and a positive number 'k,' find the
// maximum sum of any contiguous subarray of size 'k'.
//
// Example 1:
//
// Input: arr = [2, 1, 5, 1, 3, 2], k=3
// Output: 9
// Explanation: Subarray with maximum sum is [5, 1, 3].
// Example 2:
//
// Input: arr = [2, 3, 4, 1, 5], k=2
// Output: 7
// Explanation: Subarray with maximum sum is [3, 4].

export function findMaxSumSubArray(k: number, arr: number[]): number {
  let windowSum = 0;
  let maxSum = 0;
  let windowStart = 0;
  for (let windowEnd = 0; windowEnd < arr.length; windowEnd++) {
    windowSum += arr[windowEnd]; // add the next element
    // slide the window, no need to slide if we've not hit the window size
    // of 'k'
    if (windowEnd >= k - 1) {
      maxSum = Math.max(maxSum, windowSum);
      windowSum -= arr[windowStart]; // subtract the element going out
      windowStart++; // slide the window ahead
    }
  }
  return maxSum;
}
