// Given a string and a pattern, find all anagrams of the pattern in the given
// string.
// Every anagram is a permutation of a string.
// As we know, when we are not allowed to repeat characters while finding
// permutations of a string,
// we get  permutations (or anagrams) of a string having  characters. For
// example, here are the six anagrams of the string abc:
//
// abc
// acb
// bac
// bca
// cab
// cba
//
// Write a function to return a list of starting indices of the anagrams of the
// pattern in the given string.
//
// Example 1:
// Input: str="ppqp", pattern="pq"
// Output: [1, 2]
// Explanation: The two anagrams of the pattern in the given string are "pq" and
// "qp".
//
// Example 2:
// Input: str="abbcabc", pattern="abc"
// Output: [2, 3, 4]
// Explanation: The three anagrams of the pattern in the given string are "bca",
// "cab", and "abc".
//
// Constraints:
// 1 <= s.length, p.length <= 3 * 104
// str and pattern consist of lowercase English letters.

export function findStringAnagrams(s: string, pattern: string): number[] {
  let windowStart = 0;
  let matched = 0;
  const charFrequencyMap = new Map<string, number>();
  for (const chr of pattern) {
    charFrequencyMap.set(chr, (charFrequencyMap.get(chr) ?? 0) + 1);
  }

  const resultIndices: number[] = [];
  // our goal is to match all the characters from the map with the current
  // window
  for (let windowEnd = 0; windowEnd < s.length; windowEnd++) {
    const rightChar = s[windowEnd];
    const rightCount = charFrequencyMap.get(rightChar);
    if (rightCount !== undefined) {
      // decrement the frequency of the matched character
      charFrequencyMap.set(rightChar, rightCount - 1);
      if (rightCount - 1 === 0) {
        matched++;
      }
    }

    if (matched === charFrequencyMap.size) {
      // have we found an anagram?
      resultIndices.push(windowStart);
    }

    if (windowEnd >= pattern.length - 1) {
      // shrink the window
      const leftChar = s[windowStart];
      windowStart++;
      const leftCount = charFrequencyMap.get(leftChar);
      if (leftCount !== undefined) {
        if (leftCount === 0) {
          // before putting the character back, decrement the matched count
          matched--;
        }
        // put the character back
        charFrequencyMap.set(leftChar, leftCount + 1);
      }
    }
  }
  return resultIndices;
}
