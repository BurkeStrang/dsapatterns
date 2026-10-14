// Given a Bitonic array, find if a given ‘key’ is present in it.
// An array is considered bitonic if it is first monotonically increasing and
// then monotonically decreasing.
// In other words,
// a bitonic array starts with a sequence of increasing elements,
// reaches a peak element,
// and then follows with a sequence of decreasing elements.
// The peak element is the maximum value in the array.
// Write a function to return the index of the ‘key’.
// If the 'key' appears more than once, return the smaller index.
// If the ‘key’ is not present, return -1.
//
// Example 1:
// Input: [1, 3, 8, 4, 3], key=4
// Output: 3
//
// Example 2:
// Input: [3, 8, 3, 1], key=8
// Output: 1
//
// Example 3:
// Input: [1, 3, 8, 12], key=12
// Output: 3
//
// Example 4:
// Input: [10, 9, 8], key=10
// Output: 0

export function findMax(arr: number[]): number {
  let start = 0;
  let end = arr.length - 1;
  while (start < end) {
    const mid = start + Math.floor((end - start) / 2);
    if (arr[mid] > arr[mid + 1]) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  // at the end of the while loop, 'start === end'
  return start;
}

// searchWithin is an order-agnostic binary search
export function searchWithin(
  arr: number[],
  key: number,
  start: number,
  end: number,
): number {
  while (start <= end) {
    const mid = start + Math.floor((end - start) / 2);
    if (key === arr[mid]) {
      return mid;
    }
    if (arr[start] < arr[end]) {
      // ascending order
      if (key < arr[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else if (key > arr[mid]) {
      // descending order
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1; // element is not found
}

// searchBitonic searches for a key in a bitonic array
export function searchBitonic(arr: number[], key: number): number {
  const maxIndex = findMax(arr);
  const keyIndex = searchWithin(arr, key, 0, maxIndex);
  if (keyIndex !== -1) {
    return keyIndex;
  }
  return searchWithin(arr, key, maxIndex + 1, arr.length - 1);
}
