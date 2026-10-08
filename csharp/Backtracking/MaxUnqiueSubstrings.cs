namespace DsaPatterns.Backtracking;

// Given a string s,
// return the maximum number of unique substrings that the given string can be
// split into.
// You can split string s into any list of non-empty substrings,
// where the concatenation of the substrings forms the original string.
// However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.
//
// Example 1:
// Input: s = "aab"
// Output: 2
// Explanation: Two possible ways to split the given string into maximum unique
// substrings are:
// ['a', 'ab'] & ['aa', 'b'], both have 2 substrings;
// hence the maximum number of unique substrings in
// which the given string can be split is 2.
//
// Example 2:
// Input: s = "abcabc"
// Output: 4
// Explanation: Four possible ways to split into maximum unique substrings are:
// ['a', 'b', 'c', 'abc'] & ['a', 'b', 'cab', 'c'] &  ['a', 'bca', 'b', 'c'] &
// ['abc', 'a', 'b', 'c'],
// all have 4 substrings.
//
// Constraints:
// 1 <= s.length <= 16
// s contains only lower case English letters.

internal static class MaxUnqiueSubstrings
{
    internal static int MaxUniqueSplit(string str)
    {
        return SplitAndCount(str, 0, []);
    }

    private static int SplitAndCount(string str, int start, HashSet<string> set)
    {
        if (start == str.Length)
        {
            return set.Count;
        }

        int count = 0;
        for (int i = start + 1; i <= str.Length; i++)
        {
            string substr = str[start..i];
            if (set.Add(substr))
            {
                count = Math.Max(count, SplitAndCount(str, i, set));
                set.Remove(substr);
            }
        }

        return count;
    }
}
