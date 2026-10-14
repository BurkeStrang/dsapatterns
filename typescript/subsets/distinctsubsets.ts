// example1: [1,3] => [[], [1], [3], [1,3]]
// example2: [1,5,3] => [[], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]]

export function findSubsets(nums: number[]): number[][] {
  // start by adding the empty subset
  const subsets: number[][] = [[]];
  // subsets = [[]]
  for (const currentNumber of nums) {
    // ===== Iteration 1 =====
    // currentNumber = 1
    // ===== Iteration 2 =====
    // currentNumber = 3

    // we will take all existing subsets and insert the current number in
    // them
    const n = subsets.length;
    for (let i = 0; i < n; i++) {
      // -------- EXAMPLE WALKTHROUGH --------
      // INPUT: nums = [1,3]
      // Before any loops:
      // subsets = [[]]

      // ===============================
      // OUTER LOOP 1
      // currentNumber = 1
      // n = 1
      //
      // INNER LOOP:
      //
      // i = 0
      // subsets[i] = []
      // set (copy of subsets[i]) = []
      // after push currentNumber:
      // set = [1]
      //
      // subsets becomes:
      // [[], [1]]
      // ===============================

      // ===============================
      // OUTER LOOP 2
      // currentNumber = 3
      // n = 2  (because subsets now has 2 items)
      //
      // INNER LOOP:
      //
      // i = 0
      // subsets[0] = []
      // set = []
      // after push:
      // set = [3]
      //
      // subsets becomes:
      // [[], [1], [3]]
      //
      // i = 1
      // subsets[1] = [1]
      // set = [1]
      // after push:
      // set = [1,3]
      //
      // subsets becomes:
      // [[], [1], [3], [1,3]]
      // ===============================
      const set = [...subsets[i], currentNumber];
      subsets.push(set);
    }
  }
  return subsets;
}
