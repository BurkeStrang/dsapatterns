use std::collections::HashMap;

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

pub fn find_string_anagrams(s: &str, pattern: &str) -> Vec<usize> {
    let s = s.as_bytes();
    let mut window_start = 0;
    let mut matched = 0;
    let mut char_frequency_map: HashMap<u8, i32> = HashMap::new();
    for &chr in pattern.as_bytes() {
        *char_frequency_map.entry(chr).or_insert(0) += 1;
    }

    let mut result_indices = Vec::new();
    // our goal is to match all the characters from the map with the current
    // window
    for window_end in 0..s.len() {
        // decrement the frequency of the matched character
        if let Some(count) = char_frequency_map.get_mut(&s[window_end]) {
            *count -= 1;
            if *count == 0 {
                matched += 1;
            }
        }

        if matched == char_frequency_map.len() {
            // have we found an anagram?
            result_indices.push(window_start);
        }

        if window_end + 1 >= pattern.len() {
            // shrink the window
            let left_char = s[window_start];
            window_start += 1;
            if let Some(count) = char_frequency_map.get_mut(&left_char) {
                if *count == 0 {
                    // before putting the character back, decrement the
                    // matched count
                    matched -= 1;
                }
                // put the character back
                *count += 1;
            }
        }
    }
    result_indices
}
