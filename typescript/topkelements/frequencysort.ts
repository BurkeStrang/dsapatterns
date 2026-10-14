// Given a string, sort it based on the decreasing frequency of its characters.
//
// Example 1:
// Input: "Programming"
// Output: "rrggmmPiano"
// Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before
// any other character.
//
// Example 2:
// Input: "abcbab"
// Output: "bbbaac"
// Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared
// only once.

import { countLetters } from "./shared.ts";

export function sortCharacterByFrequency(s: string): string {
  // Find the frequency of each character
  const characterFrequencyMap = countLetters(s);

  // Sort the character-frequency pairs by frequency in descending order
  const characterFrequencyPairs = [...characterFrequencyMap].sort(
    (a, b) => b[1] - a[1],
  );

  // Build a string, appending the most occurring characters first
  let sortedString = "";
  for (const [character, frequency] of characterFrequencyPairs) {
    sortedString += character.repeat(frequency);
  }
  return sortedString;
}
