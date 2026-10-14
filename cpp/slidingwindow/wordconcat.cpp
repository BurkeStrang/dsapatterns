#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

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

std::vector<int> find_word_concatenation(const std::string &s,
                                         const std::vector<std::string> &words)
{
    std::unordered_map<std::string_view, int> word_frequency_map;
    for (const std::string &word : words)
    {
        word_frequency_map[word]++;
    }

    std::vector<int> result_indices;
    int words_count = std::ssize(words);
    int word_length = std::ssize(words[0]);
    std::string_view text = s;

    for (int i = 0; i <= std::ssize(s) - words_count * word_length; i++)
    {
        std::unordered_map<std::string_view, int> words_seen;
        for (int j = 0; j < words_count; j++)
        {
            int next_word_index = i + j * word_length;
            // get the next word from the string
            std::string_view word = text.substr(next_word_index, word_length);
            // break if we don't need this word
            auto needed = word_frequency_map.find(word);
            if (needed == word_frequency_map.end())
            {
                break;
            }

            // add the word to the 'words_seen' map
            words_seen[word]++;

            // no need to process further if the word has higher frequency
            // than required
            if (words_seen[word] > needed->second)
            {
                break;
            }

            if (j + 1 == words_count)
            {
                // store index if we have found all the words
                result_indices.push_back(i);
            }
        }
    }
    return result_indices;
}
