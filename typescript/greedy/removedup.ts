// Given a string s,
// remove all duplicate letters from the input string while maintaining the
// original order of the letters.
// Additionally,
// the returned string should be the smallest in lexicographical order among all
// possible results.
// A string is in the smallest lexicographical order if it appears first in a
// dictionary.
// For example, "abc" is smaller than "acb" because "abc" comes first
// alphabetically.
//
// Example 1
// Input: "babac"
// Expected Output: "abc"
// Justification:
// After removing 1 b and 1 a from the input string, we can get bac, and abc
// strings.
// The final answer is 'abc', which is the smallest lexicographical string
// without duplicate letters.
//
// Example 2
// Input: "zabccde"
// Expected Output: "zabcde"
// Justification: Removing one of the 'c's forms 'zabcde', the smallest string
// in lexicographical order without duplicates.
//
// Example 3
// Input: "mnopmn"
// Expected Output: "mnop"
// Justification: Removing the second 'm' and 'n' gives 'mnop', which is the
// smallest possible string without duplicate characters.

export function removeDuplicateLetters(s: string): string {
  const count = new Map<string, number>();
  const present = new Set<string>();
  // an array of characters works as a stack: push and pop work on its end
  const result: string[] = [];

  // Count the frequency of each character
  for (const c of s) {
    count.set(c, (count.get(c) ?? 0) + 1);
  }

  for (const c of s) {
    if (!present.has(c)) {
      // Ensure smallest lexicographical order based off conditions of:
      // Has Result
      // Is Smaller
      // Can Remove Last
      let last = result.at(-1);
      while (last !== undefined && c < last && (count.get(last) ?? 0) > 0) {
        present.delete(last);
        result.pop();
        last = result.at(-1);
      }

      result.push(c);
      present.add(c);
    }
    count.set(c, (count.get(c) ?? 0) - 1); // Decrease the frequency
  }

  return result.join("");
}
