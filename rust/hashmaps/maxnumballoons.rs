use std::collections::HashMap;

// Given a string, determine the maximum number of times the word "balloon" can
// be formed using the characters from the string.
// Each character in the string can be used only once.
//
// Example 1:
// Input: "balloonballoon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice from the given string.
//
// Example 2:
// Input: "bbaall"
// Expected Output: 0
// Justification: The word "balloon" cannot be formed from the given string as
// we are missing the character 'o' twice.
//
// Example 3:
// Input: "balloonballoooon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice, even though there are
// extra 'o' characters.
//
// Constraints:
// 1 <= text.length <= 104
// text consists of lower case English letters only.

pub fn max_number_of_balloons(text: &str) -> usize {
    let mut freq: HashMap<char, usize> = HashMap::new();
    for letter in text.chars() {
        *freq.entry(letter).or_insert(0) += 1;
    }

    let mut min_result = text.len();
    for letter in ['b', 'a', 'l', 'o', 'n'] {
        let count = freq.get(&letter).copied().unwrap_or(0);
        if letter == 'l' || letter == 'o' {
            min_result = min_result.min(count / 2);
        } else {
            min_result = min_result.min(count);
        }
    }
    min_result
}
