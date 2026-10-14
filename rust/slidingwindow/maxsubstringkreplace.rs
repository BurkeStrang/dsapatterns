use std::collections::HashMap;

// Given a string with lowercase letters only, if you are allowed to replace no
// more than ‘k’ letters with any letter,
// find the length of the longest substring having the same letters after
// replacement.
//
// Example 1:
// Input: str="aabccbb", k=2
// Output: 5
// Explanation: Replace the two 'c' with 'b' to have a longest repeating
// substring "bbbbb".
//
// Example 2:
// Input: str="abbcb", k=1
// Output: 4
// Explanation: Replace the 'c' with 'b' to have a longest repeating substring
// "bbbb".
//
// Example 3:
// Input: str="abccde", k=1
// Output: 3
// Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating
// substring "ccc".
// Constraints:
//
// 1 <= str.length <=
// s consists of only lowercase English letters.
// 0 <= k <= s.length

pub fn max_length_replace(s: &str, k: usize) -> usize {
    let s = s.as_bytes();
    let mut window_start = 0;
    let mut max_length = 0;
    let mut max_repeat_letter_count = 0;
    let mut letter_frequency_map: HashMap<u8, usize> = HashMap::new();
    // try to extend the range [window_start, window_end]
    for window_end in 0..s.len() {
        let right_count =
            letter_frequency_map.entry(s[window_end]).or_insert(0);
        *right_count += 1;
        // we don't need to place the max_repeat_letter_count under the below
        // 'if', see the explanation in the 'Solution' section above.
        max_repeat_letter_count = max_repeat_letter_count.max(*right_count);
        // current window size is from window_start to window_end, overall we
        // have a letter which is repeating 'max_repeat_letter_count' times,
        // this means we can have a window which has one letter repeating
        // 'max_repeat_letter_count' times and the remaining letters we should
        // replace. If the remaining letters are more than 'k', it is the time
        // to shrink the window as we are not allowed to replace more than 'k'
        // letters
        if window_end - window_start + 1 - max_repeat_letter_count > k {
            *letter_frequency_map.get_mut(&s[window_start]).unwrap() -= 1;
            window_start += 1;
        }
        max_length = max_length.max(window_end - window_start + 1);
    }
    max_length
}
