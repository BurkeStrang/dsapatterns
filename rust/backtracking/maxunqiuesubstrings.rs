use std::collections::HashSet;

// Given a string s,
// return the maximum number of unique substrings that the given string can be
// split into.
// You can split string s into any list of non-empty substrings,
// where the concatenation of the substrings forms the original string.
// However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.
//
// Example 1:
// Input: s = "aab"
// Output: 2
// Explanation: Two possible ways to split the given string into maximum unique
// substrings are:
// ['a', 'ab'] & ['aa', 'b'], both have 2 substrings;
// hence the maximum number of unique substrings in
// which the given string can be split is 2.
//
// Example 2:
// Input: s = "abcabc"
// Output: 4
// Explanation: Four possible ways to split into maximum unique substrings are:
// ['a', 'b', 'c', 'abc'] & ['a', 'b', 'cab', 'c'] &  ['a', 'bca', 'b', 'c'] &
// ['abc', 'a', 'b', 'c'],
// all have 4 substrings.
//
// Constraints:
// 1 <= s.length <= 16
// s contains only lower case English letters.

pub fn max_unique_split(s: &str) -> usize {
    split_and_count(s, 0, &mut HashSet::new())
}

fn split_and_count<'a>(
    s: &'a str,
    start: usize,
    set: &mut HashSet<&'a str>,
) -> usize {
    if start == s.len() {
        return set.len();
    }

    let mut count = 0;
    for i in start + 1..=s.len() {
        let substr = &s[start..i];
        // insert returns false if the substring was already in the set
        if set.insert(substr) {
            count = count.max(split_and_count(s, i, set));
            set.remove(substr);
        }
    }

    count
}
