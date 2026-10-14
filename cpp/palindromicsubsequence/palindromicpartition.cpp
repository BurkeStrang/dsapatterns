#include <algorithm>
#include <string>
#include <vector>

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

int find_mpp_cuts(const std::string &st)
{
    int n = std::ssize(st);
    if (n == 0)
    {
        return 0;
    }

    // is_palindrome[i][j] will be 'true' if the string from index 'i' to
    // index 'j' is a palindrome
    std::vector<std::vector<bool>> is_palindrome(n, std::vector<bool>(n));

    // every string with one character is a palindrome
    for (int i = 0; i < n; i++)
    {
        is_palindrome[i][i] = true;
    }

    // populate is_palindrome table
    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        for (int end_index = start_index + 1; end_index < n; end_index++)
        {
            // if it's a two-character string or if the remaining string is a
            // palindrome too
            if (st[start_index] == st[end_index] &&
                (end_index - start_index == 1 ||
                 is_palindrome[start_index + 1][end_index - 1]))
            {
                is_palindrome[start_index][end_index] = true;
            }
        }
    }

    // now let's populate the second table, every index in 'cuts' stores the
    // minimum cuts needed for the substring from that index till the end
    std::vector<int> cuts(n);
    for (int start_index = n - 1; start_index >= 0; start_index--)
    {
        int min_cuts = n; // maximum cuts
        for (int end_index = n - 1; end_index >= start_index; end_index--)
        {
            if (is_palindrome[start_index][end_index])
            {
                // we can cut here as we got a palindrome
                // also, we don't need any cut if the whole substring is a
                // palindrome
                if (end_index == n - 1)
                {
                    min_cuts = 0;
                }
                else
                {
                    min_cuts = std::min(min_cuts, 1 + cuts[end_index + 1]);
                }
            }
        }
        cuts[start_index] = min_cuts;
    }

    return cuts[0];
}
