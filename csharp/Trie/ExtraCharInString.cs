namespace DsaPatterns.Trie;

// Given a string s and an array of words words.
// Break string s into multiple non-overlapping substrings such that each
// substring should be part of the words.
// There are some characters left which are not part of any substring.
// Return the minimum number of remaining characters in s,
// which are not part of any substring after string break-up.
//
// Example 1:
// Input: s = "amazingracecar", dictionary = ["race", "car"]
// Expected Output: 7
// Justification: The string s can be rearranged to form "racecar", leaving 'a',
// 'm', 'a', 'z', 'i', 'n', 'g' as extra.
//
// Example 2:
// Input: s = "bookkeeperreading", dictionary = ["keep", "read"]
// Expected Output: 9
// Justification: The words "keep" and "read" can be formed from s, but 'b',
// 'o', 'o', 'k', 'e', 'r', 'i', 'n', 'g' are extra.
//
// Example 3:
// Input: s = "thedogbarksatnight", dictionary = ["dog", "bark", "night"]
// Expected Output: 6
// Justification: The words "dog", "bark", and "night" can be formed, leaving
// 't', 'h', 'e', 's', 'a', 't' as extra characters.
//
// Constraints:
// 1 <= str.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words

internal class ExtraCharInString
{
    private int[] memo = [];
    private HashSet<string> wordSet = [];

    internal int MinExtraChar(string s, string[] dictionary)
    {
        int length = s.Length;
        memo = new int[length];
        Array.Fill(memo, -1); // Initialize memoization array with -1
        wordSet = [.. dictionary]; // Populate set with dictionary words
        return Solve(0, length, s);
    }

    private int Solve(int index, int length, string s)
    {
        // Base case: when we reach the end of the string
        if (index == length)
        {
            return 0;
        }

        // Return the cached result if already computed
        if (memo[index] != -1)
        {
            return memo[index];
        }

        // Count the current character as an extra character
        int minExtra = Solve(index + 1, length, s) + 1;

        // Try forming substrings starting from the current index
        for (int end = index; end < length; end++)
        {
            string substring = s[index..(end + 1)]; // Current substring
            // Check if the substring is in the dictionary
            if (wordSet.Contains(substring))
            {
                // Update minimum extra characters
                minExtra = Math.Min(minExtra, Solve(end + 1, length, s));
            }
        }

        // Store the result in the memo and return
        memo[index] = minExtra;
        return minExtra;
    }
}
