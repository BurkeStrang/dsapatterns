"""
You’re given a string s and a list of words words, where all words have the
same length.

A concatenated substring is formed by joining all the words from any
permutation of words — each used exactly once,
without any extra characters in between.

For example, if words = ["ab", "cd", "ef"], then valid concatenated strings
include
"abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab".
A string like "acdbef" is not valid because it doesn't match any complete
permutation of the given words.

Return all starting indices in s where such concatenated substrings appear.
You can return the indices in any order.

Example 1:
Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" &
"foxcat".

Example 2:
Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".

Constraints:
1 <= words.length <= 104
1 <= words[i].length <= 30
words[i] consists of only lowercase English letters.
All the strings of words are unique.
1 <= sum(words[i].length) <= 105
"""

from collections import Counter, defaultdict


def find_word_concatenation(s: str, words: list[str]) -> list[int]:
    word_frequency_map = Counter(words)

    result_indices: list[int] = []
    words_count = len(words)
    word_length = len(words[0])

    for i in range(len(s) - words_count * word_length + 1):
        words_seen: defaultdict[str, int] = defaultdict(int)
        for j in range(words_count):
            next_word_index = i + j * word_length
            # get the next word from the string
            word = s[next_word_index : next_word_index + word_length]
            # break if we don't need this word
            if word not in word_frequency_map:
                break

            # add the word to the 'words_seen' map
            words_seen[word] += 1

            # no need to process further if the word has higher frequency
            # than required
            if words_seen[word] > word_frequency_map[word]:
                break

            if j + 1 == words_count:
                # store index if we have found all the words
                result_indices.append(i)
    return result_indices
