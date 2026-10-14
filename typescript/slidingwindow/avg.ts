// Given an array, find the average of each subarray of ‘K’ contiguous
// elements in it.

export function findAverages(k: number, arr: number[]): number[] {
  const result: number[] = [];
  let windowSum = 0;
  let windowStart = 0;
  for (let windowEnd = 0; windowEnd < arr.length; windowEnd++) {
    windowSum += arr[windowEnd]; // add the next element
    // slide the window, we don't need to slide if we've not hit the
    // required window size of 'k'
    if (windowEnd >= k - 1) {
      result.push(windowSum / k); // calculate the average
      windowSum -= arr[windowStart]; // subtract the element going out
      windowStart++; // slide the window ahead
    }
  }
  return result;
}
