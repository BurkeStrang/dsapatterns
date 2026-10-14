use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

// Given a string,
// find if its letters can be rearranged in such a way that no two same
// characters come next to each other.
//
// Example 1:
// Input: "aappp"
// Output: "papap"
// Explanation: In "papap", none of the repeating characters come next to each
// other.
//
// Example 2:
// Input: "Programming"
// Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
// Explanation: None of the repeating characters come next to each other.
//
// Example 3:
// Input: "aapa"
// Output: ""
// Explanation: In all arrangements of "aapa", atleast two 'a' will come
// together e.g., "apaa", "paaa".

pub fn rearrange_string(s: &str) -> String {
    let mut char_frequency_map: HashMap<char, usize> = HashMap::new();
    for chr in s.chars() {
        *char_frequency_map.entry(chr).or_insert(0) += 1;
    }

    // a max heap of (frequency, letter); wrapping the letter in Reverse makes
    // the earlier letter come first among letters with the same frequency
    let mut max_heap: BinaryHeap<(usize, Reverse<char>)> = char_frequency_map
        .into_iter()
        .map(|(chr, count)| (count, Reverse(chr)))
        .collect();

    let mut result = String::new();
    // the character used in the previous step, kept out of the heap for one
    // step so that it can't be picked twice in a row
    let mut previous: Option<(usize, Reverse<char>)> = None;

    while let Some((count, Reverse(current_char))) = max_heap.pop() {
        // the previous character can be added back to the heap now, if there
        // is any of it left
        if let Some(entry) = previous.take()
            && entry.0 > 0
        {
            max_heap.push(entry);
        }

        // append the current character to the result string and decrement its
        // count
        result.push(current_char);
        previous = Some((count - 1, Reverse(current_char)));
    }

    // if we were successful in appending all the characters to the result
    // string, return it
    if result.len() == s.len() {
        return result;
    }
    String::new()
}
