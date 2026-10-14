// You’re given a string s and a list of words words, where all words have the
// same length.
//
// A concatenated substring is formed by joining all the words from any
// permutation of words — each used exactly once,
// without any extra characters in between.
//
// For example, if words = ["ab", "cd", "ef"], then valid concatenated strings
// include
// "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab".
// A string like "acdbef" is not valid because it doesn't match any complete
// permutation of the given words.
//
// Return all starting indices in s where such concatenated substrings appear.
// You can return the indices in any order.
//
// Example 1:
// Input: String="catfoxcat", Words=["cat", "fox"]
// Output: [0, 3]
// Explanation: The two substring containing both the words are "catfox" &
// "foxcat".
//
// Example 2:
// Input: String="catcatfoxfox", Words=["cat", "fox"]
// Output: [3]
// Explanation: The only substring containing both the words is "catfox".
//
// Constraints:
// 1 <= words.length <= 104
// 1 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// All the strings of words are unique.
// 1 <= sum(words[i].length) <= 105

export function findWordConcatenation(s: string, words: string[]): number[] {
  const wordFrequencyMap = new Map<string, number>();
  for (const word of words) {
    wordFrequencyMap.set(word, (wordFrequencyMap.get(word) ?? 0) + 1);
  }

  const resultIndices: number[] = [];
  const wordsCount = words.length;
  const wordLength = words[0].length;

  for (let i = 0; i <= s.length - wordsCount * wordLength; i++) {
    const wordsSeen = new Map<string, number>();
    for (let j = 0; j < wordsCount; j++) {
      const nextWordIndex = i + j * wordLength;
      // get the next word from the string
      const word = s.slice(nextWordIndex, nextWordIndex + wordLength);
      // break if we don't need this word
      const needed = wordFrequencyMap.get(word);
      if (needed === undefined) {
        break;
      }

      // add the word to the 'wordsSeen' map
      const seen = (wordsSeen.get(word) ?? 0) + 1;
      wordsSeen.set(word, seen);

      // no need to process further if the word has higher frequency than
      // required
      if (seen > needed) {
        break;
      }

      if (j + 1 === wordsCount) {
        // store index if we have found all the words
        resultIndices.push(i);
      }
    }
  }
  return resultIndices;
}
