// In a non-empty array of numbers,
// every number appears exactly twice except two numbers that appear only once.
// Find the two numbers that appear only once.
//
// Example 1:
// Input: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5]
// Output: [4, 6]
//
// Example 2:
// Input: [2, 1, 3, 2]
// Output: [1, 3]

export function findSingleNumbers(nums: number[]): number[] {
  // Get the XOR of all the numbers
  let n1xn2 = 0;
  for (const num of nums) {
    n1xn2 ^= num;
  }

  // Get the rightmost bit that is '1'
  let rightmostSetBit = 1;
  while ((rightmostSetBit & n1xn2) === 0) {
    rightmostSetBit <<= 1;
  }

  let num1 = 0;
  let num2 = 0;
  for (const num of nums) {
    if ((num & rightmostSetBit) !== 0) {
      // the bit is set
      num1 ^= num;
    } else {
      // the bit is not set
      num2 ^= num;
    }
  }

  return [num1, num2];
}
