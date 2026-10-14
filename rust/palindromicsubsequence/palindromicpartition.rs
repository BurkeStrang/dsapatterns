// Given a string, we want to cut it into pieces such that each piece is a
// palindrome.
// Write a function to return the minimum number of cuts needed.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: Palindrome pieces are "a", "bdb", "c", "a".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Palindrome pieces are "c", "d", "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: Palindrome pieces are "p", "q", "r".
//
// Example 4:
// Input: = "pp"
// Output: 0
// Explanation: We do not need to cut, as "pp" is a palindrome.
// Constraints:
//
// 1 <= st.length <= 16
// s contains only lowercase English letters.

pub fn find_mpp_cuts(st: &str) -> usize {
    let st = st.as_bytes();
    let n = st.len();
    if n == 0 {
        return 0;
    }

    // is_palindrome[i][j] will be 'true' if the string from index 'i' to
    // index 'j' is a palindrome
    let mut is_palindrome = vec![vec![false; n]; n];

    // every string with one character is a palindrome
    for i in 0..n {
        is_palindrome[i][i] = true;
    }

    // populate is_palindrome table
    for start_index in (0..n).rev() {
        for end_index in start_index + 1..n {
            // if it's a two-character string or if the remaining string is a
            // palindrome too
            if st[start_index] == st[end_index]
                && (end_index - start_index == 1
                    || is_palindrome[start_index + 1][end_index - 1])
            {
                is_palindrome[start_index][end_index] = true;
            }
        }
    }

    // now let's populate the second table, every index in 'cuts' stores the
    // minimum cuts needed for the substring from that index till the end
    let mut cuts = vec![0; n];
    for start_index in (0..n).rev() {
        let mut min_cuts = n; // maximum cuts
        for end_index in (start_index..n).rev() {
            if is_palindrome[start_index][end_index] {
                // we can cut here as we got a palindrome
                // also, we don't need any cut if the whole substring is a
                // palindrome
                if end_index == n - 1 {
                    min_cuts = 0;
                } else {
                    min_cuts = min_cuts.min(1 + cuts[end_index + 1]);
                }
            }
        }
        cuts[start_index] = min_cuts;
    }

    cuts[0]
}
