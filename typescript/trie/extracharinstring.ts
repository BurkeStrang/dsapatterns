// Given a string s and an array of words words.
// Break string s into multiple non-overlapping substrings such that each
// substring should be part of the words.
// There are some characters left which are not part of any substring.
// Return the minimum number of remaining characters in s,
// which are not part of any substring after string break-up.
//
// Example 1:
// Input: s = "amazingracecar", dictionary = ["race", "car"]
// Expected Output: 7
// Justification: The string s can be rearranged to form "racecar", leaving 'a',
// 'm', 'a', 'z', 'i', 'n', 'g' as extra.
//
// Example 2:
// Input: s = "bookkeeperreading", dictionary = ["keep", "read"]
// Expected Output: 9
// Justification: The words "keep" and "read" can be formed from s, but 'b',
// 'o', 'o', 'k', 'e', 'r', 'i', 'n', 'g' are extra.
//
// Example 3:
// Input: s = "thedogbarksatnight", dictionary = ["dog", "bark", "night"]
// Expected Output: 6
// Justification: The words "dog", "bark", and "night" can be formed, leaving
// 't', 'h', 'e', 's', 'a', 't' as extra characters.
//
// Constraints:
// 1 <= str.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words

export function solve(
  index: number,
  s: string,
  wordSet: Set<string>,
  memo: (number | null)[],
): number {
  // Base case: when we reach the end of the string
  if (index === s.length) {
    return 0;
  }

  // Return the cached result if already computed
  const cached = memo[index];
  if (cached !== null) {
    return cached;
  }

  // Count the current character as an extra character
  let minExtra = solve(index + 1, s, wordSet, memo) + 1;

  // Try forming substrings starting from the current index
  for (let end = index; end < s.length; end++) {
    const substring = s.slice(index, end + 1);
    // Check if the substring is in the dictionary
    if (wordSet.has(substring)) {
      // Update minimum extra characters
      minExtra = Math.min(minExtra, solve(end + 1, s, wordSet, memo));
    }
  }

  // Store the result in the memo and return
  memo[index] = minExtra;
  return minExtra;
}

export function minExtraChar(s: string, dictionary: string[]): number {
  // No answer has been worked out yet, for any index
  const memo = new Array<number | null>(s.length).fill(null);
  // Populate a set with the dictionary words
  const wordSet = new Set(dictionary);
  return solve(0, s, wordSet, memo);
}
