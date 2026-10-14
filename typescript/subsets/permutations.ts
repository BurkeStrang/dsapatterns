// Given a set of distinct numbers, find all of its permutations.
//
// Example 1:
// Input: [1,3,5]
// Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]

export function findPermutations(nums: number[]): number[][] {
  const result: number[][] = [];
  let permutations: number[][] = [[]];
  for (const currentNumber of nums) {
    // we will take all existing permutations and add the current number to
    // create new permutations
    const nextPermutations: number[][] = [];
    for (const oldPermutation of permutations) {
      // create a new permutation by adding the current number at every
      // position
      for (let j = 0; j <= oldPermutation.length; j++) {
        const newPermutation = [...oldPermutation];
        newPermutation.splice(j, 0, currentNumber);
        if (newPermutation.length === nums.length) {
          result.push(newPermutation);
        } else {
          nextPermutations.push(newPermutation);
        }
      }
    }
    permutations = nextPermutations;
  }
  return result;
}
