// Given two strings,
// one representing a ransom note and the other representing the available
// letters from a magazine,
// determine if it's possible to construct the ransom note using only the
// letters from the magazine.
// Each letter from the magazine can be used only once.
//
// Example 1:
// Input: Ransom Note = "hello", Magazine = "hellworld"
// Expected Output: true
// Justification: The word "hello" can be constructed from the letters in
// "hellworld".
//
// Example 2:
// Input: Ransom Note = "notes", Magazine = "stoned"
// Expected Output: true
// Justification: The word "notes" can be fully constructed from "stoned" from
// its first 5 letters.
//
// Example 3:
// Input: Ransom Note = "apple", Magazine = "pale"
// Expected Output: false
// Justification: The word "apple" cannot be constructed from "pale" as we are
// missing one 'p'.
//
// Constraints:
// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

pub fn can_construct(ransom_note: &str, magazine: &str) -> bool {
    let mut freq = [0; 26];

    for &letter in magazine.as_bytes() {
        freq[usize::from(letter - b'a')] += 1;
    }

    for &letter in ransom_note.as_bytes() {
        let idx = usize::from(letter - b'a');
        if freq[idx] == 0 {
            return false;
        }
        freq[idx] -= 1;
    }

    true
}
