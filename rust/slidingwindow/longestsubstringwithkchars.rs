use std::collections::HashMap;

// Given a string, find the length of the longest substring in it with no more
// than K distinct characters.
// You can assume that K is less than or equal to the length of the given
// string.
//
// Example 1:
// Input: String="araaci", K=2
// Output: 4
// Explanation: The longest substring with no more than '2' distinct characters
// is "araa".
//
// Example 2:
// Input: String="araaci", K=1
// Output: 2
// Explanation: The longest substring with no more than '1' distinct characters
// is "aa".
//
// Example 3:
// Input: String="cbbebi", K=3
// Output: 5
// Explanation: The longest substrings with no more than '3' distinct characters
// are "cbbeb" & "bbebi".
// Constraints:
//
// 1 <= str.length <= 5 * 104
// 0 <= K <= 50

pub fn find_length(s: &str, k: usize) -> usize {
    let s = s.as_bytes();
    let mut window_start = 0;
    let mut max_length = 0;
    let mut char_frequency_map: HashMap<u8, usize> = HashMap::new();
    // in the following loop we'll try to extend the range
    // [window_start, window_end]
    for window_end in 0..s.len() {
        let right_char = s[window_end];
        *char_frequency_map.entry(right_char).or_insert(0) += 1;
        // shrink the sliding window, until we are left with 'k' distinct
        // characters in the frequency map
        while char_frequency_map.len() > k {
            let left_char = s[window_start];
            let count = char_frequency_map.get_mut(&left_char).unwrap();
            *count -= 1;
            if *count == 0 {
                char_frequency_map.remove(&left_char);
            }
            window_start += 1; // shrink the window
        }
        // remember the maximum length so far
        max_length = max_length.max(window_end - window_start + 1);
    }
    max_length
}
