namespace DsaPatterns.PalindromicSubsequence;

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

internal static class PalindromicPartition
{
    internal static int FindMppCuts(string st)
    {
        // isPalindrome[i, j] will be 'true' if the string from index 'i' to
        // index 'j' is a palindrome
        bool[,] isPalindrome = new bool[st.Length, st.Length];

        // every string with one character is a palindrome
        for (int i = 0; i < st.Length; i++)
        {
            isPalindrome[i, i] = true;
        }

        // populate isPalindrome table
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
                        || isPalindrome[startIndex + 1, endIndex - 1]
                    )
                    {
                        isPalindrome[startIndex, endIndex] = true;
                    }
                }
            }
        }

        // now let's populate the second table, every index in 'cuts' stores
        // the minimum cuts needed for the substring from that index till the
        // end
        int[] cuts = new int[st.Length];
        for (int startIndex = st.Length - 1; startIndex >= 0; startIndex--)
        {
            int minCuts = st.Length; // maximum cuts
            for (
                int endIndex = st.Length - 1;
                endIndex >= startIndex;
                endIndex--
            )
            {
                if (isPalindrome[startIndex, endIndex])
                {
                    // we can cut here as we got a palindrome
                    // also, we don't need any cut if the whole substring is a
                    // palindrome
                    if (endIndex == st.Length - 1)
                    {
                        minCuts = 0;
                    }
                    else
                    {
                        minCuts = Math.Min(minCuts, 1 + cuts[endIndex + 1]);
                    }
                }
            }

            cuts[startIndex] = minCuts;
        }

        return cuts[0];
    }
}
