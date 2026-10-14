use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap, VecDeque};

// Given a string and a number ‘K’,
// find if the string can be rearranged such that the same characters are at
// least ‘K’ distance apart from each other.
//
// Example 1:
// Input: "mmpp", K=2
// Output: "mpmp" or "pmpm"
// Explanation: All same characters are 2 distance apart.
//
// Example 2:
// Input: "Programming", K=3
// Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
// Explanation: All same characters are 3 distance apart.
//
// Example 3:
// Input: "aab", K=2
// Output: "aba"
// Explanation: All same characters are 2 distance apart.
//
// Example 4:
// Input: "aappa", K=3
// Output: ""
// Explanation: We cannot find an arrangement of the string where any two 'a'
// are 3 distance apart.

pub fn reorganize_string(s: &str, k: usize) -> String {
    if k <= 1 {
        return s.to_string();
    }

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
    let mut queue = VecDeque::new();

    while let Some((frequency, Reverse(letter))) = max_heap.pop() {
        // append the current character to the result string and decrement its
        // count
        result.push(letter);
        // the character has to wait for 'k' steps before it can be used again
        queue.push_back((frequency - 1, Reverse(letter)));

        if queue.len() == k {
            let entry = queue.pop_front().unwrap();
            if entry.0 > 0 {
                max_heap.push(entry);
            }
        }
    }

    // if we were successful in appending all the characters to the result
    // string, return it
    if result.len() == s.len() {
        return result;
    }
    String::new()
}
