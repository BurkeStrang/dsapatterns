// Numbers can be regarded as the product of their factors.
// For example, 8 = 2 x 2 x 2 = 2 x 4.
// Given an integer n,
// return all possible combinations of its factors.
// You may return the answer in any order.
//
// Example 1:
// Input: n = 8
// Output: [[2, 2, 2], [2, 4]]
//
// Example 2:
// Input: n = 20
// Output: [[2, 2, 5], [2, 10], [4, 5]]
//
// Constraints:
// 2 <= n <= 107

export function getAllFactors(
  n: number,
  start: number,
  curr: number[],
  result: number[][],
): void {
  // go up to the square root of 'n'
  for (let i = start; i * i <= n; i++) {
    if (n % i === 0) {
      curr.push(i);
      // 'i' and 'n / i' finish off a combination
      result.push([...curr, n / i]);
      // keep 'i' and break 'n / i' down further
      getAllFactors(n / i, i, curr, result);
      curr.pop();
    }
  }
}

export function getFactors(n: number): number[][] {
  const result: number[][] = [];
  getAllFactors(n, 2, [], result);
  return result;
}
