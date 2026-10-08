namespace DsaPatterns.TwoPointers;

// Problem Statement
// Given a sorted array, create a new array containing squares of all the
// numbers of the input array in the sorted order.
//
// Example 1:
//
// Input: [-2, -1, 0, 2, 3]
// Output: [0, 1, 4, 4, 9]
// Example 2:
//
// Input: [-3, -1, 0, 1, 2]
// Output: [0, 1, 1, 4, 9]
// Constraints:
//
// 1 <= arr.length <= 104
// -104 <= arr[i] <= 104
// arr is sorted in non-decreasing order.

internal static class SquareASortedArray
{
    internal static int[] MakeSquares(int[] arr)
    {
        int n = arr.Length;
        int[] squares = new int[n];
        // Initialize an index for the highest value in the output array.
        int highestSquareIdx = n - 1;
        // Initialize two pointers, left and right, for the input array.
        int left = 0;
        int right = n - 1;

        // Traverse the input array from both ends towards the center.
        while (left <= right)
        {
            // Calculate the square of the element at the left pointer.
            int leftSquare = arr[left] * arr[left];
            // Calculate the square of the element at the right pointer.
            int rightSquare = arr[right] * arr[right];

            // Compare the squared values and store the larger one in the
            // output array.
            if (leftSquare > rightSquare)
            {
                // Store the left squared value in the output array.
                squares[highestSquareIdx] = leftSquare;
                highestSquareIdx--; // Move the output index to the left.
                left++; // Move the left pointer to the right.
            }
            else
            {
                // Store the right squared value in the output array.
                squares[highestSquareIdx] = rightSquare;
                highestSquareIdx--; // Move the output index to the left.
                right--; // Move the right pointer to the left.
            }
        }

        return squares;
    }
}
