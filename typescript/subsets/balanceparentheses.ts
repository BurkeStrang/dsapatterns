// For a given number 'num', write a function to generate all combinations of
// 'num' pairs of balanced parentheses.
//
// Example 1:
// Input: num=2
// Output: (()), ()()
//
// Example 2:
// Input: num=3
// Output: ((())), (()()), (())(), ()(()), ()()()

interface ParenthesesString {
  str: string;
  openCount: number; // open parentheses count
  closeCount: number; // close parentheses count
}

export function generateValidParentheses(num: number): string[] {
  const result: string[] = [];
  const queue: ParenthesesString[] = [{ str: "", openCount: 0, closeCount: 0 }];
  // a for-of loop over an array also visits the items pushed onto it while
  // the loop runs, so the array works as the queue
  for (const ps of queue) {
    // if we've reached the maximum number of open and close parentheses, add
    // to result
    if (ps.openCount === num && ps.closeCount === num) {
      result.push(ps.str);
    } else {
      // if we can add an open parentheses, add it
      if (ps.openCount < num) {
        queue.push({
          str: ps.str + "(",
          openCount: ps.openCount + 1,
          closeCount: ps.closeCount,
        });
      }

      // if we can add a close parentheses, add it
      if (ps.openCount > ps.closeCount) {
        queue.push({
          str: ps.str + ")",
          openCount: ps.openCount,
          closeCount: ps.closeCount + 1,
        });
      }
    }
  }
  return result;
}
