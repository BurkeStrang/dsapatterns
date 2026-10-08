#include <stdlib.h>

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

// The squares are returned in a new array, the same length as the input,
// that the caller must free.
int *make_squares
(
    const int *arr,
    int arr_len
)
{
    int n = arr_len;
    int *squares = malloc((size_t)n * sizeof(int));
    // Initialize an index for the highest value in the output array.
    int highest_square_idx = n - 1;
    // Initialize two pointers, left and right, for the input array.
    int left = 0;
    int right = n - 1;

    // Traverse the input array from both ends towards the center.
    while (left <= right)
    {
        // Calculate the square of the element at the left pointer.
        int left_square = arr[left] * arr[left];
        // Calculate the square of the element at the right pointer.
        int right_square = arr[right] * arr[right];

        // Compare the squared values and store the larger one in the output
        // array.
        if (left_square > right_square)
        {
            // Store the left squared value in the output array.
            squares[highest_square_idx] = left_square;
            highest_square_idx--; // Move the output index to the left.
            left++;               // Move the left pointer to the right.
        }
        else
        {
            // Store the right squared value in the output array.
            squares[highest_square_idx] = right_square;
            highest_square_idx--; // Move the output index to the left.
            right--;              // Move the right pointer to the left.
        }
    }
    return squares;
}
