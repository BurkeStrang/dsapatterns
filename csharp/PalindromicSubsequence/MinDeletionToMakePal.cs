namespace DsaPatterns.PalindromicSubsequence;

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

internal static class MinDeletionToMakePal
{
    internal static int FindMinimumDeletions(string st)
    {
        return st.Length - FindLpsLen(st);
    }

    private static int FindLpsLen(string st)
    {
        int[,] dp = new int[st.Length, st.Length];
        for (int i = 0; i < st.Length; i++)
        {
            dp[i, i] = 1;
        }

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
                    dp[startIndex, endIndex] =
                        2 + dp[startIndex + 1, endIndex - 1];
                }
                else
                {
                    dp[startIndex, endIndex] = Math.Max(
                        dp[startIndex + 1, endIndex],
                        dp[startIndex, endIndex - 1]
                    );
                }
            }
        }

        return dp[0, st.Length - 1];
    }
}
