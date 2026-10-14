use std::cmp::Reverse;
use std::collections::HashMap;

// Given a string, sort it based on the decreasing frequency of its characters.
//
// Example 1:
// Input: "Programming"
// Output: "rrggmmPiano"
// Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before
// any other character.
//
// Example 2:
// Input: "abcbab"
// Output: "bbbaac"
// Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared
// only once.

pub fn sort_character_by_frequency(s: &str) -> String {
    // Find the frequency of each character
    let mut character_frequency_map: HashMap<char, usize> = HashMap::new();
    for chr in s.chars() {
        *character_frequency_map.entry(chr).or_insert(0) += 1;
    }

    // Create a list of character-frequency pairs for sorting
    let mut character_frequency_pairs: Vec<(char, usize)> =
        character_frequency_map.into_iter().collect();

    // Sort the character-frequency pairs by frequency in descending order
    character_frequency_pairs.sort_by_key(|pair| Reverse(pair.1));

    // Build a string, appending the most occurring characters first
    let mut sorted_string = String::with_capacity(s.len());
    for (character, frequency) in character_frequency_pairs {
        for _ in 0..frequency {
            sorted_string.push(character);
        }
    }

    sorted_string
}
