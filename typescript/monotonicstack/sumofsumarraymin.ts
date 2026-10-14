// Given an array of integers arr, return the sum of the minimum values from all
// possible contiguous subarrays within arr.
// Since the result can be very large, return the final sum modulo (109 + 7).
//
// Example 1:
// Input: arr = [3, 1, 2, 4, 5]
// Expected Output: 30
// Explanation:
// The subarrays are: [3], [1], [2], [4], [5], [3,1], [1,2], [2,4], [4,5],
// [3,1,2], [1,2,4], [2,4,5], [3,1,2,4], [1, 2, 4, 5], [3, 1, 2, 4, 5].
// The minimum values of these subarrays are: 3, 1, 2, 4, 5, 1, 1, 2, 4, 1, 1,
// 2, 1, 1, 1.
// Summing these minimums: 3 + 1 + 2 + 4 + 5 + 1 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1
// + 1 = 30.
//
// Example 2:
// Input: arr = [2, 6, 5, 4]
// Expected Output: 36
// Explanation:
// The subarrays are: [2], [6], [5], [4], [2,6], [6,5], [5,4], [2,6,5], [6,5,4],
// [2,6,5,4].
// The minimum values of these subarrays are: 2, 6, 5, 4, 2, 5, 4, 2, 4, 2.
// Summing these minimums: 2 + 6 + 5 + 4 + 2 + 5 + 4 + 2 + 4 + 2 = 36.
//
// Example 3:
// Input: arr = [7, 3, 8]
// Expected Output: 35
// Explanation:
// The subarrays are: [7], [3], [8], [7,3], [3,8], [7,3,8].
// The minimum values of these subarrays are: 7, 3, 8, 3, 3, 3.
// Summing these minimums: 7 + 3 + 8 + 3 + 3 + 3 = 27.
//
// Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

const MOD = 1_000_000_007;

export function sumSubarrayMins(arr: number[]): number {
  const n = arr.length;
  let result = 0; // Final sum of subarray minimums
  const stack: number[] = [];

  // Iterate through the array plus one extra iteration for a sentinel.
  for (let currentIndex = 0; currentIndex <= n; currentIndex++) {
    // If we reached the end, use 0 as a sentinel value; otherwise, use the
    // current element. It helps to process all remaining elements in the
    // stack.
    const currentElement = currentIndex < n ? arr[currentIndex] : 0;

    // Process elements in the stack while the current element is smaller
    // than the element at the top. Here, we maintain monotonic increasing
    // stack.
    let minIndex = stack.at(-1);
    while (minIndex !== undefined && arr[minIndex] > currentElement) {
      // Pop the index whose corresponding element is greater than
      // currentElement.
      stack.pop();

      // Calculate the number of subarrays where arr[minIndex] is the
      // minimum:
      // 'ending' is the count of subarrays ending at minIndex; they can start
      // anywhere after the previous index on the stack, or from the start of
      // the array if the stack is empty,
      // and 'starting' is the count of subarrays starting at minIndex that
      // can extend until currentIndex.
      const previous = stack.at(-1);
      const ending =
        previous === undefined ? minIndex + 1 : minIndex - previous;
      const starting = currentIndex - minIndex;
      const countSubarrays = ending * starting;

      // Add the contribution of arr[minIndex] for these subarrays to the
      // result.
      result = (result + ((arr[minIndex] * countSubarrays) % MOD)) % MOD;
      minIndex = previous;
    }

    // Push the current index onto the stack for further processing.
    stack.push(currentIndex);
  }

  return result;
}
