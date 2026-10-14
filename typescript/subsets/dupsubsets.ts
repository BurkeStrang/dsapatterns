// Given a set of numbers that might contain duplicates, find all of its
// distinct subsets.
//
// Example 1:
// Input: [1, 3, 3]
// Output: [], [1], [3], [1,3], [3,3], [1,3,3]
//
// Example 2:
// Input: [1, 5, 3, 3]
// Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3],
// [3,3,5], [1,5,3,3]

export function findDupSubsets(nums: number[]): number[][] {
  // sort the numbers to handle duplicates
  nums.sort((a, b) => a - b);
  const subsets: number[][] = [[]];
  // the subsets added in the previous step start here
  let previousStepStart = 0;
  for (let i = 0; i < nums.length; i++) {
    let startIndex = 0;
    // if current and the previous elements are same, create new subsets
    // only from the subsets added in the previous step
    if (i > 0 && nums[i] === nums[i - 1]) {
      startIndex = previousStepStart;
    }
    previousStepStart = subsets.length;
    for (let j = startIndex; j < previousStepStart; j++) {
      // create a new subset from the existing subset and add the current
      // element to it
      subsets.push([...subsets[j], nums[i]]);
    }
  }
  return subsets;
}
