use std::collections::HashMap;

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

pub fn find_word_concatenation(s: &str, words: &[&str]) -> Vec<usize> {
    let mut word_frequency_map: HashMap<&str, usize> = HashMap::new();
    for &word in words {
        *word_frequency_map.entry(word).or_insert(0) += 1;
    }

    let mut result_indices = Vec::new();
    let words_count = words.len();
    let word_length = words[0].len();
    if s.len() < words_count * word_length {
        return result_indices;
    }

    for i in 0..=s.len() - words_count * word_length {
        let mut words_seen: HashMap<&str, usize> = HashMap::new();
        for j in 0..words_count {
            let next_word_index = i + j * word_length;
            // get the next word from the string
            let word = &s[next_word_index..next_word_index + word_length];
            // break if we don't need this word
            let Some(&needed) = word_frequency_map.get(word) else {
                break;
            };

            // add the word to the 'words_seen' map
            let seen = words_seen.entry(word).or_insert(0);
            *seen += 1;

            // no need to process further if the word has higher frequency
            // than required
            if *seen > needed {
                break;
            }

            if j + 1 == words_count {
                // store index if we have found all the words
                result_indices.push(i);
            }
        }
    }
    result_indices
}
