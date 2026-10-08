namespace DsaPatterns.PalindromicSubsequence;

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

internal static class CountPalindromicSubstring
{
    internal static int FindCps(string st)
    {
        // dp[i, j] will be 'true' if the string from index 'i' to index 'j' is
        // a palindrome
        bool[,] dp = new bool[st.Length, st.Length];
        int count = 0;

        // every string with one character is a palindrome
        for (int i = 0; i < st.Length; i++)
        {
            dp[i, i] = true;
            count++;
        }

        // abdbca
        // dp (6 x 6) = [
        //         [true,false,false,false,false,false],
        //         [false,true,false,false,false,false],
        //         [false,false,true,false,false,false],
        //         [false,false,false,true,false,false],
        //         [false,false,false,false,true,false],
        //         [false,false,false,false,false,true],
        // ]

        for (int startIndex = st.Length - 1; startIndex >= 0; startIndex--)
        {
            for (
                int endIndex = startIndex + 1;
                endIndex < st.Length;
                endIndex++
            )
            {
                if (st[startIndex] == st[endIndex])
                {
                    // if it's a two-character string or if the remaining
                    // string is a palindrome too
                    if (
                        endIndex - startIndex == 1
                        || dp[startIndex + 1, endIndex - 1]
                    )
                    {
                        dp[startIndex, endIndex] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
}
