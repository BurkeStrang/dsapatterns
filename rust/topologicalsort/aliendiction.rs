use std::collections::{HashMap, VecDeque};

// There is a dictionary containing words from an alien language
// for which we don't know the ordering of the letters.
// Given a list of strings words from the alien language's dictionary.
// All strings in words are sorted lexicographically by the rules of this new
// language.
// Return a string of the unique letters in the new alien language
// sorted in lexicographically increasing order by the new language's rules.
// It is given that the input is a valid dictionary and there exists an ordering
// among its letters.
//
// Example 1:
// Input: Words: ["ba", "bc", "ac", "cab"]
// Output: bac
// Explanation: Given that the words are sorted lexicographically by the rules
// of the alien language, so
// from the given words we can conclude the following ordering among its
// characters:
// 1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
// 2. From "bc" and "ac", we can conclude that 'b' comes before 'a'
// From the above two points, we can conclude that the correct character order
// is: "bac"
//
// Example 2:
// Input: Words: ["cab", "aaa", "aab"]
// Output: cab
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
// 2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
// From the above two points, we can conclude that the correct character order
// is: "cab"
//
// Example 3:
// Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
// Output: ywxz
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
// 2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
// 3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
// 4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
// 5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'
//
// From the above five points, we can conclude that the correct character order
// is: "ywxz"
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

pub fn find_alien_order(words: &[&str]) -> String {
    if words.is_empty() {
        return String::new();
    }

    // a. Initialize the graph
    let mut in_degree: HashMap<u8, usize> = HashMap::new();
    let mut graph: HashMap<u8, Vec<u8>> = HashMap::new();
    // letters in the order they first appear, so the sources are always
    // visited in the same order
    let mut letters = Vec::new();
    for word in words {
        for character in word.bytes() {
            in_degree.entry(character).or_insert(0);
            graph.entry(character).or_insert_with(|| {
                // only runs the first time the letter is seen
                letters.push(character);
                Vec::new()
            });
        }
    }

    // b. Build the graph
    for pair in words.windows(2) {
        // find ordering of characters from adjacent words
        let (w1, w2) = (pair[0].as_bytes(), pair[1].as_bytes());
        let mut found_difference = false;
        for (&parent, &child) in w1.iter().zip(w2) {
            if parent != child {
                graph.get_mut(&parent).unwrap().push(child);
                *in_degree.get_mut(&child).unwrap() += 1;
                found_difference = true;
                break;
            }
        }

        // a word cannot come before one of its own prefixes: "abc" before
        // "ab" is not a valid dictionary, so no letter ordering can explain
        // it
        if !found_difference && w1.len() > w2.len() {
            return String::new();
        }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    let mut sources = VecDeque::new();
    for &letter in &letters {
        if in_degree[&letter] == 0 {
            sources.push_back(letter);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees if a child's in-degree becomes zero,
    // add it to sources queue
    let mut sorted_order = String::new();
    while let Some(vertex) = sources.pop_front() {
        sorted_order.push(char::from(vertex));
        for child in &graph[&vertex] {
            let degree = in_degree.get_mut(child).unwrap();
            *degree -= 1;
            if *degree == 0 {
                sources.push_back(*child);
            }
        }
    }

    // if sorted_order doesn't contain all characters, there is a cyclic
    // dependency between characters, therefore, we will not be able to find
    // the correct ordering of the characters
    if sorted_order.len() != in_degree.len() {
        return String::new();
    }

    sorted_order
}
