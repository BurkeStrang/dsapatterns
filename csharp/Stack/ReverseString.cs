using System.Text;

namespace DsaPatterns.Stack;

// Given a string, write a function that uses a stack to reverse the string. The
// function should return the reversed string.
//
// Example 1:
// Input: "Hello, World!"
// Output: "!dlroW ,olleH"
//
// Example 2:
// Input: "OpenAI"
// Output: "IAnepO"
//
// Example 3:
// Input: "Stacks are fun!"
// Output: "!nuf era skcatS"
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is a printable ascii character.

internal static class ReverseString
{
    internal static string Reverse(string input)
    {
        StringBuilder reverseList = new(input.Length);
        Stack<char> stack = new(input);

        // pop all letters from stack to reverseList
        while (stack.Count > 0)
        {
            reverseList.Append(stack.Pop());
        }

        return reverseList.ToString();
    }
}
