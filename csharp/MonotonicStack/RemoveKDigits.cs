using System.Text;

namespace DsaPatterns.MonotonicStack;

// Given a non-negative integer represented as a string num and an integer k,
// delete k digits from num to obtain the smallest possible integer.
// Return this minimum possible integer as a string.
//
// Examples
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: The digits removed are 4, 3, and 2 forming the new number 1219
// which is the smallest.
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Removing the leading 1 forms the smallest number 200.
//
// Input: num = "1901042", k = 4
// Output: "2"
// Explanation: Removing 1, 9, 1, and 4 forms the number 2 which is the smallest
// possible.
//
// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

internal static class RemoveKDigits
{
    internal static string RemoveKdigits(string num, int k)
    {
        // a StringBuilder used as a stack of digits
        StringBuilder stack = new();

        foreach (char digit in num)
        {
            while (k > 0 && stack.Length > 0 && stack[^1] > digit)
            {
                stack.Length--;
                k--;
            }

            stack.Append(digit);
        }

        // Truncate the remaining K digits
        for (int i = 0; i < k; i++)
        {
            stack.Length--;
        }

        // Convert Stack to String
        string result = stack.ToString();

        // Remove any leading zeros
        while (result.Length > 1 && result[0] == '0')
        {
            result = result[1..];
        }

        // If the String is empty return "0"
        if (result.Length == 0)
        {
            return "0";
        }

        return result;
    }
}
