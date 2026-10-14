use std::collections::HashMap;

// Given a string, determine the length of the longest palindrome that can be
// constructed using the characters from the string.
// Return the maximum possible length of the palindromic string.
//
// Examples:
//
// Input: "applepie"
// Expected Output: 5
// Justification: The longest palindrome that can be constructed from the string
// is "pepep",
// which has a length of 5.
// There are are other palindromes too but they all will be of length 5.
//
// Input: "aabbcc"
// Expected Output: 6
// Justification: We can form the palindrome "abccba" using the characters from
// the string,
// which has a length of 6.
//
// Input: "bananas"
// Expected Output: 5
// Justification: The longest palindrome that can be constructed from the string
// is "anana",
// which has a length of 5.
//
// Constraints:
// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.

pub fn longest_palindrome(s: &str) -> usize {
    let mut char_freq: HashMap<char, usize> = HashMap::new();

    // Populate the map with character frequencies
    for c in s.chars() {
        *char_freq.entry(c).or_insert(0) += 1;
    }

    let mut length = 0;
    let mut odd_found = false;

    // Calculate the palindrome length
    // This calculation is based on the fact that for a palindrome, we can use
    // all characters with even frequencies and at most one character with an
    // odd frequency.
    // So even characters contribute their full frequency to the length, while
    // odd characters only contribute their frequency minus one (to make it
    // even), and we can have at most one odd character in the middle of the
    // palindrome.
    for &freq in char_freq.values() {
        if freq % 2 == 0 {
            length += freq;
        } else {
            length += freq - 1;
            odd_found = true;
        }
    }

    // Add the central character if any odd frequency was found
    if odd_found {
        length += 1;
    }

    length
}
