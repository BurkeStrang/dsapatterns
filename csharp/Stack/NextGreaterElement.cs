namespace DsaPatterns.Stack;

// Given an array, print the Next Greater Element (NGE) for every element.
//
// The Next Greater Element for an element x is the first greater element on the
// right side of x in the array.
//
// Elements for which no greater element exist, consider the next greater
// element as -1.
//
// Examples
// Example 1:
//
//  Input: [4, 5, 2, 25]
//  Output: [5, 25, 25, -1]
//  Explanation: The NGE for 4 is 5, 5 is 25, 2 is 25, and there is no NGE for
// 25.
// Example 1:
//
//  Input: [13, 7, 6, 12]
//  Output: [-1, 12, 12, -1]
// Example 1:
//
//  Input: [1, 2, 3, 4, 5]
//  Output: [2, 3, 4, 5, -1]
// Constraints:
//
// 1 <= arr.length <= 104
// -10^9 <= arr[i] <= 10^9

internal static class NextGreaterElement
{
    internal static int[] NextLargerElement(int[] arr)
    {
        int n = arr.Length;
        Stack<int> s = new(); // Create a stack.
        int[] res = new int[n]; // Create an array to store the results.

        // Iterate through the input array in reverse order.
        for (int i = n - 1; i >= 0; i--)
        {
            // Remove elements from the stack while they are less than or equal
            // to the current element.
            while (s.Count > 0 && s.Peek() <= arr[i])
            {
                s.Pop();
            }

            if (s.Count == 0)
            {
                // If the stack is empty, there is no greater element to the
                // right.
                res[i] = -1;
            }
            else
            {
                // Otherwise, the greater element is the top element of the
                // stack.
                res[i] = s.Peek();
            }

            // Push the current element onto the stack.
            s.Push(arr[i]);
        }

        return res;
    }
}
