// Given a string, find the length of the longest substring in it with no more
// than K distinct characters.
// You can assume that K is less than or equal to the length of the given
// string.
//
// Example 1:
// Input: String="araaci", K=2
// Output: 4
// Explanation: The longest substring with no more than '2' distinct characters
// is "araa".
//
// Example 2:
// Input: String="araaci", K=1
// Output: 2
// Explanation: The longest substring with no more than '1' distinct characters
// is "aa".
//
// Example 3:
// Input: String="cbbebi", K=3
// Output: 5
// Explanation: The longest substrings with no more than '3' distinct characters
// are "cbbeb" & "bbebi".
// Constraints:
//
// 1 <= str.length <= 5 * 104
// 0 <= K <= 50

export function findLength(s: string, k: number): number {
  let windowStart = 0;
  let maxLength = 0;
  const charFrequencyMap = new Map<string, number>();
  // in the following loop we'll try to extend the range
  // [windowStart, windowEnd]
  for (let windowEnd = 0; windowEnd < s.length; windowEnd++) {
    const rightChar = s[windowEnd];
    charFrequencyMap.set(rightChar, (charFrequencyMap.get(rightChar) ?? 0) + 1);
    // shrink the sliding window, until we are left with 'k' distinct
    // characters in the frequency map
    while (charFrequencyMap.size > k) {
      const leftChar = s[windowStart];
      const count = (charFrequencyMap.get(leftChar) ?? 0) - 1;
      if (count === 0) {
        charFrequencyMap.delete(leftChar);
      } else {
        charFrequencyMap.set(leftChar, count);
      }
      windowStart++; // shrink the window
    }
    // remember the maximum length so far
    maxLength = Math.max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}
