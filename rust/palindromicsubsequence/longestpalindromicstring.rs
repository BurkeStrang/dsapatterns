// Given a string, find the length of its Longest Palindromic Substring (LPS).
// In a palindromic string, elements read the same backward and forward.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: LPS is "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

pub fn find_lp_string_length(st: &str) -> usize {
    palindrome_length(st.as_bytes())
}

// The Go version passes a start and an end index around. A slice already
// knows where it starts and ends, so here each call gets a shorter slice.
fn palindrome_length(st: &[u8]) -> usize {
    let n = st.len();
    if n == 0 {
        return 0;
    }

    // every string with one character is a palindrome
    if n == 1 {
        return 1;
    }

    // case 1: elements at the beginning and the end are the same
    if st[0] == st[n - 1] {
        let remaining_length = n - 2;
        // check if the remaining string is also a palindrome
        if remaining_length == palindrome_length(&st[1..n - 1]) {
            return remaining_length + 2;
        }
    }

    // case 2: skip one character either from the beginning or the end
    let c1 = palindrome_length(&st[1..]);
    let c2 = palindrome_length(&st[..n - 1]);
    c1.max(c2)
}
