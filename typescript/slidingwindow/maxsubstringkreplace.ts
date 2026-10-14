// Given a string with lowercase letters only, if you are allowed to replace no
// more than ‘k’ letters with any letter,
// find the length of the longest substring having the same letters after
// replacement.
//
// Example 1:
// Input: str="aabccbb", k=2
// Output: 5
// Explanation: Replace the two 'c' with 'b' to have a longest repeating
// substring "bbbbb".
//
// Example 2:
// Input: str="abbcb", k=1
// Output: 4
// Explanation: Replace the 'c' with 'b' to have a longest repeating substring
// "bbbb".
//
// Example 3:
// Input: str="abccde", k=1
// Output: 3
// Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating
// substring "ccc".
// Constraints:
//
// 1 <= str.length <=
// s consists of only lowercase English letters.
// 0 <= k <= s.length

export function maxLengthReplace(s: string, k: number): number {
  let windowStart = 0;
  let maxLength = 0;
  let maxRepeatLetterCount = 0;
  const letterFrequencyMap = new Map<string, number>();
  // try to extend the range [windowStart, windowEnd]
  for (let windowEnd = 0; windowEnd < s.length; windowEnd++) {
    const rightChar = s[windowEnd];
    const rightCount = (letterFrequencyMap.get(rightChar) ?? 0) + 1;
    letterFrequencyMap.set(rightChar, rightCount);
    // we don't need to place the maxRepeatLetterCount under the below 'if',
    // see the explanation in the 'Solution' section above.
    maxRepeatLetterCount = Math.max(maxRepeatLetterCount, rightCount);
    // current window size is from windowStart to windowEnd, overall we have
    // a letter which is repeating 'maxRepeatLetterCount' times, this means
    // we can have a window which has one letter repeating
    // 'maxRepeatLetterCount' times and the remaining letters we should
    // replace. If the remaining letters are more than 'k', it is the time to
    // shrink the window as we are not allowed to replace more than 'k'
    // letters
    if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k) {
      const leftChar = s[windowStart];
      letterFrequencyMap.set(
        leftChar,
        (letterFrequencyMap.get(leftChar) ?? 0) - 1,
      );
      windowStart++;
    }
    maxLength = Math.max(maxLength, windowEnd - windowStart + 1);
  }
  return maxLength;
}
