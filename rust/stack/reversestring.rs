// Given a string, write a function that uses a stack to reverse the string. The
// function should return the reversed string.
//
// Example 1:
// Input: "Hello, World!"
// Output: "!dlroW ,olleH"
//
// Example 2:
// Input: "OpenAI"
// Output: "IAnepO"
//
// Example 3:
// Input: "Stacks are fun!"
// Output: "!nuf era skcatS"
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is a printable ascii character.

pub fn reverse_string(input: &str) -> String {
    let mut reverse_list = String::with_capacity(input.len());
    let mut stack: Vec<char> = input.chars().collect();

    // pop all letters from stack to reverse_list
    while let Some(letter) = stack.pop() {
        reverse_list.push(letter);
    }

    reverse_list
}
