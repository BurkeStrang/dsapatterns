// Given an array, find the length of the smallest subarray in it which when
// sorted will sort the whole array.
//
// Example 1:
//
// Input: [1, 2, 5, 3, 7, 10, 9, 12]
// Output: 5
// Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the
// whole array sorted
// Example 2:
//
// Input: [1, 3, 2, 0, -1, 7, 10]
// Output: 5
// Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the
// whole array sorted
// Example 3:
//
// Input: [1, 2, 3]
// Output: 0
// Explanation: The array is already sorted
// Example 4:
//
// Input: [3, 2, 1]
// Output: 3
// Explanation: The whole array needs to be sorted.
// Constraints:
//
// 1 <= arr.length <= 104
// -105 <= arr[i] <= 105

export function minSort(arr: number[]): number {
  const last = arr.length - 1;
  let low = 0;
  let high = last;
  // find the first number out of sorting order from the beginning
  while (low < last && arr[low] <= arr[low + 1]) {
    low++;
  }

  if (low === last) {
    // if the array is sorted
    return 0;
  }

  // find the first number out of sorting order from the end
  while (high > 0 && arr[high] >= arr[high - 1]) {
    high--;
  }

  // find the maximum and minimum of the subarray
  let subarrayMax = -Infinity;
  let subarrayMin = Infinity;
  for (let k = low; k <= high; k++) {
    subarrayMax = Math.max(subarrayMax, arr[k]);
    subarrayMin = Math.min(subarrayMin, arr[k]);
  }

  // extend the subarray to include any number which is bigger than the
  // minimum of the subarray
  while (low > 0 && arr[low - 1] > subarrayMin) {
    low--;
  }
  // extend the subarray to include any number which is smaller than the
  // maximum of the subarray
  while (high < last && arr[high + 1] < subarrayMax) {
    high++;
  }

  return high - low + 1;
}
