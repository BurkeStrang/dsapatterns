// Given an expression containing digits and operations (+, -, *),
// find all possible ways in which the expression can be evaluated
// by grouping the numbers and operators using parentheses.
//
// Example 1:
// Input: "1+2*3"
// Output: 7, 9
// Explanation:
//   1+(2*3) => 7
//   (1+2)*3 => 9
//
// Example 2:
// Input: "2*3-4-5"
// Output: 8, -12, 7, -7, -3
// Explanation:
//   2*(3-(4-5)) => 8
//   2*(3-4-5) => -12
//   2*3-(4-5) => 7
//   2*(3-4)-5 => -7
//   (2*3)-4-5 => -3

export function diffWaysToEvaluateExpression(input: string): number[] {
  const result: number[] = [];
  // base case: if the input string is a number, parse and add it to output.
  if (!/[+\-*]/.test(input)) {
    result.push(Number(input));
    return result;
  }

  for (let i = 0; i < input.length; i++) {
    const chr = input[i];
    if (chr >= "0" && chr <= "9") {
      continue;
    }
    // break the equation here into two parts and make recursively calls
    const leftParts = diffWaysToEvaluateExpression(input.slice(0, i));
    const rightParts = diffWaysToEvaluateExpression(input.slice(i + 1));
    for (const part1 of leftParts) {
      for (const part2 of rightParts) {
        if (chr === "+") {
          result.push(part1 + part2);
        } else if (chr === "-") {
          result.push(part1 - part2);
        } else if (chr === "*") {
          result.push(part1 * part2);
        }
      }
    }
  }
  return result;
}
