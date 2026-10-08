namespace DsaPatterns.PalindromicSubsequence;

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

internal static class LongestPalindromicString
{
    internal static int FindLpStringLength(string st)
    {
        return PalindromeLength(st, 0, st.Length - 1);
    }

    private static int PalindromeLength(string st, int startIndex, int endIndex)
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
            int remainingLength = endIndex - startIndex - 1;
            if (
                remainingLength
                == PalindromeLength(st, startIndex + 1, endIndex - 1)
            )
            {
                return remainingLength + 2;
            }
        }

        int c1 = PalindromeLength(st, startIndex + 1, endIndex);
        int c2 = PalindromeLength(st, startIndex, endIndex - 1);
        if (c1 > c2)
        {
            return c1;
        }

        return c2;
    }
}
