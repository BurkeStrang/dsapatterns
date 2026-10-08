namespace DsaPatterns.Greedy;

// Given a string s,
// remove all duplicate letters from the input string while maintaining the
// original order of the letters.
// Additionally,
// the returned string should be the smallest in lexicographical order among all
// possible results.
// A string is in the smallest lexicographical order if it appears first in a
// dictionary.
// For example, "abc" is smaller than "acb" because "abc" comes first
// alphabetically.
//
// Example 1
// Input: "babac"
// Expected Output: "abc"
// Justification:
// After removing 1 b and 1 a from the input string, we can get bac, and abc
// strings.
// The final answer is 'abc', which is the smallest lexicographical string
// without duplicate letters.
//
// Example 2
// Input: "zabccde"
// Expected Output: "zabcde"
// Justification: Removing one of the 'c's forms 'zabcde', the smallest string
// in lexicographical order without duplicates.
//
// Example 3
// Input: "mnopmn"
// Expected Output: "mnop"
// Justification: Removing the second 'm' and 'n' gives 'mnop', which is the
// smallest possible string without duplicate characters.

internal static class RemoveDup
{
    internal static string RemoveDuplicateLetters(string s)
    {
        Dictionary<char, int> count = [];
        HashSet<char> present = [];
        List<char> result = [];

        // Count the frequency of each character
        foreach (char c in s)
        {
            count[c] = count.GetValueOrDefault(c) + 1;
        }

        foreach (char c in s)
        {
            if (!present.Contains(c))
            {
                // Ensure smallest lexicographical order based off conditions
                // of:
                // Has Result
                // Is Smaller
                // Can Remove Last
                while (
                    result.Count > 0 && c < result[^1] && count[result[^1]] > 0
                )
                {
                    present.Remove(result[^1]);
                    result.RemoveAt(result.Count - 1);
                }

                result.Add(c);
                present.Add(c);
            }

            count[c]--; // Decrease the frequency
        }

        return new string([.. result]);
    }
}
