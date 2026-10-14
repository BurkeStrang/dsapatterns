// Given a string and a pattern, find the smallest substring in the given string
// which has all the character occurrences of the given pattern.
//
// Example 1:
// Input: String="aabdec", Pattern="abc"
// Output: "abdec"
// Explanation: The smallest substring having all characters of the pattern is
// "abdec"
//
// Example 2:
// Input: String="aabdec", Pattern="abac"
// Output: "aabdec"
// Explanation: The smallest substring having all characters occurrences of the
// pattern is "aabdec"
//
// Example 3:
// Input: String="abdbca", Pattern="abc"
// Output: "bca"
// Explanation: The smallest substring having all characters of the pattern is
// "bca".
//
// Example 4:
// Input: String="adcad", Pattern="abc"
// Output: ""
// Explanation: No substring in the given string has all characters of the
// pattern
// Constraints:
//
// m == String.length
// n == Pattern.length
// 1 <= m, n <= 105
// String and Pattern consist of uppercase and lowercase English letters.

export function findSubstring(s: string, pattern: string): string {
  let windowStart = 0;
  let matched = 0;
  let minLength = s.length + 1;
  let subStrStart = 0;
  const charFrequencyMap = new Map<string, number>();
  for (const chr of pattern) {
    charFrequencyMap.set(chr, (charFrequencyMap.get(chr) ?? 0) + 1);
  }

  // try to extend the range [windowStart, windowEnd]
  for (let windowEnd = 0; windowEnd < s.length; windowEnd++) {
    const rightChar = s[windowEnd];
    const rightCount = charFrequencyMap.get(rightChar);
    if (rightCount !== undefined) {
      charFrequencyMap.set(rightChar, rightCount - 1);
      if (rightCount - 1 >= 0) {
        matched++;
      }
    }

    // shrink the window if we can, finish as soon as we remove a matched
    // character
    while (matched === pattern.length) {
      if (minLength > windowEnd - windowStart + 1) {
        minLength = windowEnd - windowStart + 1;
        subStrStart = windowStart;
      }

      const leftChar = s[windowStart];
      windowStart++;
      const leftCount = charFrequencyMap.get(leftChar);
      if (leftCount !== undefined) {
        // note that we could have redundant matching characters, therefore
        // we'll decrement the matched count only when a useful occurrence of
        // a matched character is going out of the window
        if (leftCount === 0) {
          matched--;
        }
        charFrequencyMap.set(leftChar, leftCount + 1);
      }
    }
  }

  if (minLength > s.length) {
    return "";
  }
  return s.slice(subStrStart, subStrStart + minLength);
}
