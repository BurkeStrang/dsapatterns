using System.Text;

namespace DsaPatterns.Stack;

// Given a positive integer n, write a function that returns its binary
// equivalent as a string.
// The function should not use any in-built binary conversion function.
//
// Example 1:
// Input: 2
// Output: "10"
// Explanation: The binary equivalent of 2 is 10.
//
// Example 2:
// Input: 7
// Output: "111"
// Explanation: The binary equivalent of 7 is 111.
//
// Example 3:
// Input: 18
// Output: "10010"
// Explanation: The binary equivalent of 18 is 10010.
//
// Constraints:
// 1 <= n <= 10^9

internal static class DecimalToBinary
{
    internal static string ToBinary(int num)
    {
        Stack<int> stack = new(); // Create an empty stack for binary digits.
        // Initialize an empty string to build the binary representation.
        StringBuilder sb = new();

        // Convert the decimal number to binary using a stack.
        while (num > 0)
        {
            // Push the remainder of num%2 (binary digit) onto the stack.
            stack.Push(num % 2);
            num /= 2; // Update num by dividing it by 2 (integer division).
        }

        // Pop binary digits from the stack and build the binary string.
        while (stack.Count > 0)
        {
            int pop = stack.Pop(); // Pop the top element from the stack.
            sb.Append(pop); // Append the popped binary digit to the result.
        }

        return sb.ToString(); // Return the binary representation as a string.
    }
}
