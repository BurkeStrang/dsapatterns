#include <stdlib.h>

// In a non-empty array of numbers,
// every number appears exactly twice except two numbers that appear only once.
// Find the two numbers that appear only once.
//
// Example 1:
// Input: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5]
// Output: [4, 6]
//
// Example 2:
// Input: [2, 1, 3, 2]
// Output: [1, 3]

// The two numbers are returned in a new array of length 2 that the caller
// must free.
int *find_single_numbers
(
    const int *nums,
    int nums_len
)
{
    // Get the XOR of all the numbers
    int n1xn2 = 0;
    for (int i = 0; i < nums_len; i++)
    {
        n1xn2 ^= nums[i];
    }

    // Get the rightmost bit that is '1'
    int rightmost_set_bit = 1;
    while ((rightmost_set_bit & n1xn2) == 0)
    {
        rightmost_set_bit <<= 1;
    }

    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < nums_len; i++)
    {
        if ((nums[i] & rightmost_set_bit) != 0)
        { // the bit is set
            num1 ^= nums[i];
        }
        else
        { // the bit is not set
            num2 ^= nums[i];
        }
    }

    int *result = malloc(2 * sizeof(int));
    result[0] = num1;
    result[1] = num2;
    return result;
}
