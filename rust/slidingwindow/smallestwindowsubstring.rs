use std::collections::HashMap;

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

pub fn find_substring(s: &str, pattern: &str) -> String {
    let bytes = s.as_bytes();
    let mut window_start = 0;
    let mut matched = 0;
    let mut min_length = s.len() + 1;
    let mut sub_str_start = 0;
    let mut char_frequency_map: HashMap<u8, i32> = HashMap::new();
    for &chr in pattern.as_bytes() {
        *char_frequency_map.entry(chr).or_insert(0) += 1;
    }

    // try to extend the range [window_start, window_end]
    for window_end in 0..bytes.len() {
        if let Some(count) = char_frequency_map.get_mut(&bytes[window_end]) {
            *count -= 1;
            if *count >= 0 {
                matched += 1;
            }
        }

        // shrink the window if we can, finish as soon as we remove a matched
        // character
        while matched == pattern.len() {
            if min_length > window_end - window_start + 1 {
                min_length = window_end - window_start + 1;
                sub_str_start = window_start;
            }

            let left_char = bytes[window_start];
            window_start += 1;
            if let Some(count) = char_frequency_map.get_mut(&left_char) {
                // note that we could have redundant matching characters,
                // therefore we'll decrement the matched count only when a
                // useful occurrence of a matched character is going out of the
                // window
                if *count == 0 {
                    matched -= 1;
                }
                *count += 1;
            }
        }
    }

    if min_length > s.len() {
        return String::new();
    }
    s[sub_str_start..sub_str_start + min_length].to_string()
}
