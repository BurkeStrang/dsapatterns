use std::collections::{HashMap, HashSet};

// Given a string s,
// remove all duplicate letters from the input string while maintaining the
// original order of the letters.
// Additionally,
// the returned string should be the smallest in lexicographical order among all
// possible results.
// A string is in the smallest lexicographical order if it appears first in a
// dictionary.
// For example, "abc" is smaller than "acb" because "abc" comes first
// alphabetically.
//
// Example 1
// Input: "babac"
// Expected Output: "abc"
// Justification:
// After removing 1 b and 1 a from the input string, we can get bac, and abc
// strings.
// The final answer is 'abc', which is the smallest lexicographical string
// without duplicate letters.
//
// Example 2
// Input: "zabccde"
// Expected Output: "zabcde"
// Justification: Removing one of the 'c's forms 'zabcde', the smallest string
// in lexicographical order without duplicates.
//
// Example 3
// Input: "mnopmn"
// Expected Output: "mnop"
// Justification: Removing the second 'm' and 'n' gives 'mnop', which is the
// smallest possible string without duplicate characters.

pub fn remove_duplicate_letters(s: &str) -> String {
    let mut count: HashMap<char, usize> = HashMap::new();
    let mut present = HashSet::new();
    // a String works as a stack of characters: push and pop work on its end
    let mut result = String::new();

    // Count the frequency of each character
    for c in s.chars() {
        *count.entry(c).or_insert(0) += 1;
    }

    for c in s.chars() {
        if !present.contains(&c) {
            // Ensure smallest lexicographical order based off conditions of:
            // Has Result
            // Is Smaller
            // Can Remove Last
            while let Some(last) = result.chars().last() {
                if c >= last || count[&last] == 0 {
                    break;
                }
                present.remove(&last);
                result.pop();
            }

            result.push(c);
            present.insert(c);
        }
        *count.get_mut(&c).unwrap() -= 1; // Decrease the frequency
    }

    result
}
