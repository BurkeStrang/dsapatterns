use std::collections::HashMap;

use super::frequencysort::sort_character_by_frequency;

// Characters with the same frequency may come out in any order, so check the
// shape of the output instead of comparing it with one fixed answer: each
// character sits in a single run as long as its frequency, and the runs never
// get longer.
fn valid_frequency_sort(input: &str, output: &str) -> bool {
    if input.len() != output.len() {
        return false;
    }

    let mut freq: HashMap<char, usize> = HashMap::new();
    for c in input.chars() {
        *freq.entry(c).or_insert(0) += 1;
    }

    let output: Vec<char> = output.chars().collect();
    let mut prev_freq = usize::MAX;
    let mut i = 0;
    while i < output.len() {
        let c = output[i];
        let mut count = 0;
        while i < output.len() && output[i] == c {
            count += 1;
            i += 1;
        }
        if freq.get(&c) != Some(&count) || count > prev_freq {
            return false;
        }
        prev_freq = count;
    }
    true
}

#[test]
fn test_sort_character_by_frequency() {
    let tests = [("Example 1", "Programming"), ("Example 2", "abcbab")];
    for (name, s) in tests {
        let got = sort_character_by_frequency(s);
        assert!(
            valid_frequency_sort(s, &got),
            "{name}: sort_character_by_frequency() = {got:?}"
        );
    }
}
