namespace DsaPatterns.PalindromicSubsequence;

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

internal static class LongestPalindromicsSubsequence
{
    internal static int FindLpsLength(string st)
    {
        return FindLpsLengthRecursive(st, 0, st.Length - 1);
    }

    private static int FindLpsLengthRecursive(
        string st,
        int startIndex,
        int endIndex
    )
    {
        if (startIndex > endIndex)
        {
            return 0;
        }

        if (startIndex == endIndex)
        {
            return 1;
        }

        if (st[startIndex] == st[endIndex])
        {
            return 2 + FindLpsLengthRecursive(st, startIndex + 1, endIndex - 1);
        }

        int c1 = FindLpsLengthRecursive(st, startIndex + 1, endIndex);
        int c2 = FindLpsLengthRecursive(st, startIndex, endIndex - 1);
        if (c1 > c2)
        {
            return c1;
        }

        return c2;
    }
}
