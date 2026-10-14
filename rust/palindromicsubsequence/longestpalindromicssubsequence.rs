// Given a sequence, find the length of its Longest Palindromic Subsequence
// (LPS).
// In a palindromic subsequence, elements read the same backward and forward.
// A subsequence is a sequence that can be derived from another sequence
// by deleting some or no elements without changing the order of the remaining
// elements.
//
// Example 1:
// Input: "abdbca"
// Output: 5
// Explanation: LPS is "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

pub fn find_lps_length(st: &str) -> usize {
    find_lps_length_recursive(st.as_bytes())
}

// The Go version passes a start and an end index around. A slice already
// knows where it starts and ends, so here each call gets a shorter slice.
fn find_lps_length_recursive(st: &[u8]) -> usize {
    let n = st.len();
    if n == 0 {
        return 0;
    }

    // every sequence with one element is a palindrome of length 1
    if n == 1 {
        return 1;
    }

    // case 1: elements at the beginning and the end are the same
    if st[0] == st[n - 1] {
        return 2 + find_lps_length_recursive(&st[1..n - 1]);
    }

    // case 2: skip one element either from the beginning or the end
    let c1 = find_lps_length_recursive(&st[1..]);
    let c2 = find_lps_length_recursive(&st[..n - 1]);
    c1.max(c2)
}
