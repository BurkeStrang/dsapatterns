using System.Text;

namespace DsaPatterns.MonotonicStack;

// You are given a string s consisting of lowercase English letters. A duplicate
// removal consists of choosing two adjacent and equal letters and removing
// them.
//
// We repeatedly make duplicate removals on s until we no longer can.
//
// Return the final string after all such duplicate removals have been made.
//
// Examples
//
// Input: s = "abccba"
// Output: ""
// Explanation: First, we remove "cc" to get "abba". Then, we remove "bb" to get
// "aa". Finally, we remove "aa" to get an empty string.
// Input: s = "foobar"
// Output: "fbar"
// Explanation: We remove "oo" to get "fbar".
// Input: s = "fooobar"
// Output: "fobar"
// Explanation: We remove the pair "oo" to get "fobar".
// Input: s = "abcd"
// Output: "abcd"
// Explanation: No adjacent duplicates so no changes.
// Constraints:
//
// 1 <= s.length <= 105
// s consists of lowercase English letters.

internal static class RemoveAdjacentDups
{
    internal static string RemoveDuplicates(string s)
    {
        // Create a StringBuilder to use as a stack
        StringBuilder stack = new();

        // Process each character in s
        foreach (char c in s)
        {
            int length = stack.Length;
            // If the stack is not empty and the current character is the same
            // as the top of the stack, pop the character from the stack
            if (length > 0 && c == stack[length - 1])
            {
                stack.Length = length - 1;
            }
            else
            {
                // Push the current character onto the stack
                stack.Append(c);
            }
        }

        // Convert the stack to a string
        return stack.ToString();
    }
}
