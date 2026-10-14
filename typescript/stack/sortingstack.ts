// Given a stack, sort it using only stack operations (push and pop).
// You can use an additional temporary stack,
//
// but you may not copy the elements into any other data structure (such as an
// array).
// The values in the stack are to be sorted in descending order, with the
// largest elements on top.
//
// Example 1. Input: [34, 3, 31, 98, 92, 23]
// Output: [3, 23, 31, 34, 92, 98]
//
// Example 2. Input: [4, 3, 2, 10, 12, 1, 5, 6]
// Output: [1, 2, 3, 4, 5, 6, 10, 12]
//
// Example 3. Input: [20, 10, -5, -1]
// Output: [-5, -1, 10, 20]

// An array is the stack here: push and pop work on its end, so the last
// element is the top.
export function sortStack(input: number[]): number[] {
  // Create a temporary stack to hold sorted elements
  const tmpStack: number[] = [];

  // Pop the top element from the input stack
  for (let tmp = input.pop(); tmp !== undefined; tmp = input.pop()) {
    // Compare the element with the top element of the temporary stack and
    // move elements from tmpStack to input stack until the correct position
    // is found
    let top = tmpStack.at(-1);
    while (top !== undefined && top > tmp) {
      input.push(top);
      tmpStack.pop();
      top = tmpStack.at(-1);
    }

    // Push the current element to the temporary stack in the correct sorted
    // position
    tmpStack.push(tmp);
  }

  return tmpStack; // Return the sorted stack
}
