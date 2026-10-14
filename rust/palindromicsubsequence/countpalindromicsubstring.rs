// Given a string, find the total number of palindromic substrings in it.
// Please note we need to find the total number of substrings and not
// subsequences.
//
// Example 1:
// Input: "abdbca"
// Output: 7
// Explanation: Here are the palindromic substrings, "a", "b", "d", "b", "c",
// "a", "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 7
// Explanation: Here are the palindromic substrings, "c", "d", "d", "p", "d",
// "dd", "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 3
// Explanation: Here are the palindromic substrings,"p", "q", "r".

pub fn find_cps(st: &str) -> usize {
    let st = st.as_bytes();
    let n = st.len();
    // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a
    // palindrome
    let mut dp = vec![vec![false; n]; n];
    let mut count = 0;

    // every string with one character is a palindrome
    for i in 0..n {
        dp[i][i] = true;
        count += 1;
    }
    // abdbca
    // dp is now 6 by 6:
    //         [true,false,false,false,false,false],
    //         [false,true,false,false,false,false],
    //         [false,false,true,false,false,false],
    //         [false,false,false,true,false,false],
    //         [false,false,false,false,true,false],
    //         [false,false,false,false,false,true],

    for start_index in (0..n).rev() {
        for end_index in start_index + 1..n {
            // if it's a two-character string or if the remaining string is a
            // palindrome too
            if st[start_index] == st[end_index]
                && (end_index - start_index == 1
                    || dp[start_index + 1][end_index - 1])
            {
                dp[start_index][end_index] = true;
                count += 1;
            }
        }
    }

    count
}
