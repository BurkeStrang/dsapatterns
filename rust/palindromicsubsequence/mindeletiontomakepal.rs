// Given a string,
// find the minimum number of characters that we can remove to make it a
// palindrome.
//
// Example 1:
// Input: "abdbca"
// Output: 1
// Explanation: By removing "c", we get a palindrome "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Deleting "cp", we get a palindrome "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: We have to remove any two characters to get a palindrome, e.g.
// if we
// remove "pq", we get palindrome "r".

pub fn find_minimum_deletions(st: &str) -> usize {
    // subtracting the length of Longest Palindromic Subsequence from the
    // length of the input string to get minimum number of deletions
    st.len() - find_lps_len(st.as_bytes())
}

fn find_lps_len(st: &[u8]) -> usize {
    let n = st.len();
    if n == 0 {
        return 0;
    }

    // dp[i][j] stores the length of LPS from index 'i' to index 'j'
    let mut dp = vec![vec![0; n]; n];

    // every sequence with one element is a palindrome of length 1
    for i in 0..n {
        dp[i][i] = 1;
    }

    for start_index in (0..n).rev() {
        for end_index in start_index + 1..n {
            if st[start_index] == st[end_index] {
                // case 1: elements at the beginning and the end are the same
                dp[start_index][end_index] =
                    2 + dp[start_index + 1][end_index - 1];
            } else {
                // case 2: skip one element either from the beginning or the
                // end
                dp[start_index][end_index] = dp[start_index + 1][end_index]
                    .max(dp[start_index][end_index - 1]);
            }
        }
    }

    dp[0][n - 1]
}
