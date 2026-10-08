namespace DsaPatterns.Stack;

// Given a string s containing (, ), [, ], {, and } characters.
// Determine if a given string of parentheses is balanced.
// A string of parentheses is considered balanced if every opening parenthesis
// has a corresponding closing parenthesis in the correct order.
//
// Example 1:
// Input: String s = "{[()]}";
// Expected Output: true
// Explanation: The parentheses in this string are perfectly balanced. Every
// opening parenthesis '{', '[', '(' has a corresponding closing parenthesis
// '}', ']', ')' in the correct order.
//
// Example 2:
// Input: string s = "{[}]";
// Expected Output: false
// Explanation: The brackets are not balanced in this string. Although it
// contains the same number of opening and closing brackets for each type, they
// are not correctly ordered. The ']' closes '[' before '{' can be closed by
// '}', and similarly, '}' closes '{' before '[' can be closed by ']'.
//
// Example 3:
// Input: String s = "(]";
// Expected Output: false
// Explanation: The parentheses in this string are not balanced. Here, ')' does
// not have a matching opening parenthesis '(', and similarly, ']' does not have
// a matching opening bracket '['.
//
// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

internal static class BalancedParentheses
{
    internal static bool ValidParentheses(string s1)
    {
        Stack<char> stack = new();
        foreach (char paren in s1)
        {
            if (paren == '(' || paren == '[' || paren == '{')
            {
                stack.Push(paren);
            }
            else
            {
                if (stack.Count == 0)
                {
                    return false;
                }

                char top = stack.Pop();
                if (
                    (paren == ')' && top != '(')
                    || (paren == ']' && top != '[')
                    || (paren == '}' && top != '{')
                )
                {
                    return false;
                }
            }
        }

        return stack.Count == 0;
    }
}
