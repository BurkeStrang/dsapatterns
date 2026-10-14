// Given a string, write a function that uses a stack to reverse the string. The
// function should return the reversed string.
//
// Example 1:
// Input: "Hello, World!"
// Output: "!dlroW ,olleH"
//
// Example 2:
// Input: "OpenAI"
// Output: "IAnepO"
//
// Example 3:
// Input: "Stacks are fun!"
// Output: "!nuf era skcatS"
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is a printable ascii character.

export function reverseString(input: string): string {
  let reverseList = "";
  const stack = Array.from(input);

  // pop all letters from stack to reverseList
  for (let letter = stack.pop(); letter !== undefined; letter = stack.pop()) {
    reverseList += letter;
  }

  return reverseList;
}
