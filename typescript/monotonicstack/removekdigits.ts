// Given a non-negative integer represented as a string num and an integer k,
// delete k digits from num to obtain the smallest possible integer.
// Return this minimum possible integer as a string.
//
// Examples
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: The digits removed are 4, 3, and 2 forming the new number 1219
// which is the smallest.
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Removing the leading 1 forms the smallest number 200.
//
// Input: num = "1901042", k = 4
// Output: "2"
// Explanation: Removing 1, 9, 1, and 4 forms the number 2 which is the smallest
// possible.
//
// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

export function removeKdigits(num: string, k: number): string {
  // An array of characters works as a stack: push and pop work on its end
  const stack: string[] = [];
  for (const digit of num) {
    let top = stack.at(-1);
    while (k > 0 && top !== undefined && top > digit) {
      stack.pop();
      k--;
      top = stack.at(-1);
    }
    stack.push(digit);
  }

  // Truncate the remaining K digits
  for (; k > 0 && stack.length > 0; k--) {
    stack.pop();
  }

  // Remove any leading zeros
  const result = stack.join("").replace(/^0+/, "");

  // If the string is empty return "0"
  return result === "" ? "0" : result;
}
