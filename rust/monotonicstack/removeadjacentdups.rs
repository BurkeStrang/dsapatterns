// You are given a string s consisting of lowercase English letters. A duplicate
// removal consists of choosing two adjacent and equal letters and removing
// them.
//
// We repeatedly make duplicate removals on s until we no longer can.
//
// Return the final string after all such duplicate removals have been made.
//
// Examples
//
// Input: s = "abccba"
// Output: ""
// Explanation: First, we remove "cc" to get "abba". Then, we remove "bb" to get
// "aa". Finally, we remove "aa" to get an empty string.
// Input: s = "foobar"
// Output: "fbar"
// Explanation: We remove "oo" to get "fbar".
// Input: s = "fooobar"
// Output: "fobar"
// Explanation: We remove the pair "oo" to get "fobar".
// Input: s = "abcd"
// Output: "abcd"
// Explanation: No adjacent duplicates so no changes.
// Constraints:
//
// 1 <= s.length <= 105
// s consists of lowercase English letters.

pub fn remove_duplicates(s: &str) -> String {
    // A String works as a stack of characters: push and pop work on its end
    let mut stack = String::new();

    // Process each character in s
    for c in s.chars() {
        if stack.ends_with(c) {
            // If the stack is not empty and the current character is the same
            // as the top of the stack, pop the character from the stack
            stack.pop();
        } else {
            // Push the current character onto the stack
            stack.push(c);
        }
    }

    stack
}
