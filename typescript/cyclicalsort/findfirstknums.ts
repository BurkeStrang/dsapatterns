// Given an unsorted array containing numbers and a number ‘k’,
// find the first ‘k’ missing positive numbers in the array.
//
// Example 1:
// Input: [3, -1, 4, 5, 5], k=3
// Output: [1, 2, 6]
// Explanation: The smallest missing positive numbers are 1, 2 and 6.
//
// Example 2:
// Input: [2, 3, 4], k=3
// Output: [1, 5, 6]
// Explanation: The smallest missing positive numbers are 1, 5 and 6.
//
// Example 3:
// Input: [-2, -3, 4], k=2
// Output: [1, 2]
// Explanation: The smallest missing positive numbers are 1 and 2.
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// 1 <= k <= 1000

export function findFirstK(nums: number[], k: number): number[] {
  const n = nums.length;
  let i = 0;
  // Phase 1: Rearrange elements to their correct positions
  while (i < n) {
    const j = nums[i] - 1;
    if (j >= 0 && j < n && nums[i] !== nums[j]) {
      // Swap elements to their correct positions
      [nums[i], nums[j]] = [nums[j], nums[i]];
    } else {
      i++;
    }
  }

  const missingNumbers: number[] = [];
  const extraNumbers = new Set<number>();
  // Phase 2: Identify missing and extra numbers
  for (let j = 0; j < n && missingNumbers.length < k; j++) {
    if (nums[j] !== j + 1) {
      missingNumbers.push(j + 1); // Track missing numbers
      extraNumbers.add(nums[j]); // Track extra numbers
    }
  }

  // Phase 3: Find remaining missing numbers
  let candidateNumber = n + 1;
  while (missingNumbers.length < k) {
    // Ignore if the array contains the candidate number
    if (!extraNumbers.has(candidateNumber)) {
      missingNumbers.push(candidateNumber);
    }
    candidateNumber++;
  }
  return missingNumbers;
}
