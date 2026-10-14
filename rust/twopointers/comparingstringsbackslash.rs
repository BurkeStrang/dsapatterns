// Given two strings containing backspaces (identified by the character ‘#’),
// check if the two strings are equal.
//
// Example 1:
//
// Input: str1="xy#z", str2="xzz#"
// Output: true
// Explanation: After applying backspaces the strings become "xz" and "xz"
// respectively.
// Example 2:
//
// Input: str1="xy#z", str2="xyz#"
// Output: false
// Explanation: After applying backspaces the strings become "xz" and "xy"
// respectively.
// Example 3:
//
// Input: str1="xp#", str2="xyz##"
// Output: true
// Explanation: After applying backspaces the strings become "x" and "x"
// respectively.
// In "xyz##", the first '#' removes the character 'z' and the second '#'
// removes the character 'y'.
// Example 4:
//
// Input: str1="xywrrmp", str2="xywrrmu#p"
// Output: true
// Explanation: After applying backspaces the strings become "xywrrmp" and
// "xywrrmp" respectively.
// Constraints:
//
// 1 <= str1.length, str2.length <= 200
// str1 and str2 only contain lowercase letters and '#' characters.

pub fn compare(str1: &str, str2: &str) -> bool {
    let str1 = str1.as_bytes();
    let str2 = str2.as_bytes();
    // the next character to look at in each string, counting from the end;
    // None once we have gone past the start
    let mut index1 = str1.len().checked_sub(1);
    let mut index2 = str2.len().checked_sub(1);
    while index1.is_some() || index2.is_some() {
        let i1 = get_next_valid_char_index(str1, index1);
        let i2 = get_next_valid_char_index(str2, index2);
        match (i1, i2) {
            // reached the end of both the strings
            (None, None) => return true,
            (Some(i1), Some(i2)) => {
                // check if the characters are equal
                if str1[i1] != str2[i2] {
                    return false;
                }
                index1 = i1.checked_sub(1);
                index2 = i2.checked_sub(1);
            }
            // reached the end of one of the strings
            _ => return false,
        }
    }
    true
}

fn get_next_valid_char_index(s: &[u8], index: Option<usize>) -> Option<usize> {
    let mut backspace_count = 0;
    let mut index = index;
    while let Some(i) = index {
        if s[i] == b'#' {
            // found a backspace character
            backspace_count += 1;
        } else if backspace_count > 0 {
            // a non-backspace character
            backspace_count -= 1;
        } else {
            break;
        }
        index = i.checked_sub(1); // skip a backspace or a valid character
    }
    index
}
