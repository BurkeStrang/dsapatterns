// Given an array of positive numbers,
// where each element represents the max number of jumps that can be made
// forward from that element,
// write a program to find the minimum number of jumps needed to reach the end
// of the array
// (starting from the first element).
// If an element is 0, then we cannot move through that element.
//
// Example 1:
// Input = {2,1,1,1,4}
// Output = 3
// Explanation: Starting from index '0', we can reach the last index through:
// 0->2->3->4
//
// Example 2:
// Input = {1,1,3,6,9,3,0,1,3}
// Output = 4
// Explanation: Starting from index '0', we can reach the last index through:
// 0->1->2->3->8

export function countMinJumpsRecursive(
  jumps: number[],
  currentIndex: number,
): number | null {
  const last = jumps.length - 1;
  // if we have reached the last index, we don't need any more jumps
  if (currentIndex >= last) {
    return 0;
  }

  // jumps[currentIndex] === 0 gives an empty range below: we can't move
  // through this element
  let totalJumps: number | null = null;
  const start = currentIndex + 1;
  const end = Math.min(currentIndex + jumps[currentIndex], last);
  // try every jump we can make from here and keep the best one
  for (let next = start; next <= end; next++) {
    const minJumps = countMinJumpsRecursive(jumps, next);
    if (minJumps === null) {
      continue;
    }
    if (totalJumps === null || minJumps + 1 < totalJumps) {
      totalJumps = minJumps + 1;
    }
  }
  return totalJumps;
}

// countMinJumps returns null if the end of the array can't be reached.
export function countMinJumps(jumps: number[]): number | null {
  return countMinJumpsRecursive(jumps, 0);
}
