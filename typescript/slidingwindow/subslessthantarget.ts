// Given an array with positive numbers and a positive target number,
// find all of its contiguous subarrays whose product is less than the target
// number.
//
// Note: This problem is very similar to the previous one.
// Here, we are trying to find all the subarrays, whereas in the previous
// problem, we focused on finding only the count of such subarrays.
//
// Example 1:
// Input: [2, 5, 3, 10], target=30
// Output: [2], [5], [2, 5], [3], [5, 3], [10]
// Explanation: There are six contiguous subarrays whose product is less than
// the target.
//
// Example 2:
// Input: [8, 2, 6, 5], target=50
// Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5]
// Explanation: There are seven contiguous subarrays whose product is less than
// the target.
//
// Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 1000
// 0 <= k <= 106

export function findSubarrays(arr: number[], target: number): number[][] {
  // Resultant list to store all valid subarrays.
  const result: number[][] = [];
  // Variable to store the product of elements in the current subarray.
  let product = 1;
  // Left boundary of the current subarray.
  let left = 0;

  // Iterate over the array using 'right' as the right boundary of the
  // current subarray.
  for (let right = 0; right < arr.length; right++) {
    // Update the product with the current element.
    product *= arr[right];

    // If the product is greater than or equal to the target, slide the
    // left boundary to the right until product is less than target.
    while (product >= target && left <= right) {
      product /= arr[left];
      left++;
    }

    // Temporary list to store the current subarray.
    const tempList: number[] = [];
    // Iterate from 'right' to 'left' and add all these subarrays to the
    // result.
    for (let i = right; i >= left; i--) {
      // Add the current element at the beginning of the list.
      tempList.unshift(arr[i]);
      // Add a copy of the current subarray to the result.
      result.push([...tempList]);
    }
  }

  // Return the result.
  return result;
}
