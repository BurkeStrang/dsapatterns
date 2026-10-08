#include "common/map.h"

// Given an array of integers, identify the highest value that appears only once
// in the array.
// If no such number exists, return -1.
//
// Example 1:
// Input: [5, 7, 3, 7, 5, 8]
// Expected Output: 8
// Justification: The number 8 is the highest value that appears only once in
// the array.
//
// Example 2:
// Input: [1, 2, 3, 2, 1, 4, 4]
// Expected Output: 3
// Justification: The number 3 is the highest value that appears only once in
// the array.
//
// Example 3:
// Input: [9, 9, 8, 8, 7, 7]
// Expected Output: -1
// Justification: There is no number in the array that appears only once.
//
// Constraints:
// 1 <= nums.length <= 2000
// 0 <= nums[i] <= 1000

int largest_unique_number
(
    const int *a,
    int a_len
)
{
    IntMap freq = {0};

    // creating map with frequencies of numbers
    for (int i = 0; i < a_len; i++)
    {
        intmap_add(&freq, a[i], 1);
    }

    int max_num = -1;
    // loop through the freq and get ones with 1
    // get the max
    int iter = 0;
    int number;
    int count;
    while (intmap_next(&freq, &iter, &number, &count))
    {
        if (count == 1 && number > max_num)
        {
            max_num = number;
        }
    }

    intmap_free(&freq);
    return max_num;
}
