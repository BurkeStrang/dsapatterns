namespace DsaPatterns.SlidingWindow;

// You’re given a string s and a list of words words, where all words have the
// same length.
//
// A concatenated substring is formed by joining all the words from any
// permutation of words — each used exactly once,
// without any extra characters in between.
//
// For example, if words = ["ab", "cd", "ef"], then valid concatenated strings
// include "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab".
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

internal static class WordConcat
{
    internal static List<int> FindWordConcatenation(string str, string[] words)
    {
        Dictionary<string, int> wordFrequencyMap = [];
        foreach (string word in words)
        {
            wordFrequencyMap[word] =
                wordFrequencyMap.GetValueOrDefault(word) + 1;
        }

        List<int> resultIndices = [];
        int wordsCount = words.Length;
        int wordLength = words[0].Length;

        for (int i = 0; i <= str.Length - (wordsCount * wordLength); i++)
        {
            Dictionary<string, int> wordsSeen = [];
            for (int j = 0; j < wordsCount; j++)
            {
                int nextWordIndex = i + (j * wordLength);
                // get the next word from the string
                string word = str.Substring(nextWordIndex, wordLength);
                // break if we don't need this word
                if (!wordFrequencyMap.TryGetValue(word, out int needed))
                {
                    break;
                }

                // add the word to the 'wordsSeen' map
                wordsSeen[word] = wordsSeen.GetValueOrDefault(word) + 1;
                // no need to process further if the word has higher frequency
                // than required
                if (wordsSeen[word] > needed)
                {
                    break;
                }

                // store index if we have found all the words
                if (j + 1 == wordsCount)
                {
                    resultIndices.Add(i);
                }
            }
        }

        return resultIndices;
    }
}
