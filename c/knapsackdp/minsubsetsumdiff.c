#include <stdlib.h>

// Given a set of positive numbers,
// partition the set into two subsets with minimum difference between their
// subset sums.
//
// Example 1:
// Input: {1, 2, 3, 9}
// Output: 3
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} &
// {9}.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}
// Output: 0
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of number is '0'. Following are the two subsets: {1, 2, 5} &
// {7, 1}.
//
// Example 3:
// Input: {1, 3, 100, 4}
// Output: 92
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} &
// {100}.

int can_partition_min_recursive
(
    const int *num,
    int num_len,
    int current_index,
    int sum1,
    int sum2
)
{
    // Base check
    if (current_index == num_len)
    {
        return abs(sum1 - sum2);
    }

    // Recursive call after including the number at the current_index in the
    // first set
    int diff1 = can_partition_min_recursive(num, num_len, current_index + 1,
                                            sum1 + num[current_index], sum2);

    // Recursive call after including the number at the current_index in the
    // second set
    int diff2 = can_partition_min_recursive(num, num_len, current_index + 1,
                                            sum1, sum2 + num[current_index]);

    return diff1 < diff2 ? diff1 : diff2;
}

int can_partition_min
(
    const int *num,
    int num_len
)
{
    return can_partition_min_recursive(num, num_len, 0, 0, 0);
}
