#include <limits.h>

// Given an array of positive numbers,
// where each element represents the max number of jumps that can be made
// forward from that element,
// write a program to find the minimum number of jumps needed to reach the end
// of the array
// (starting from the first element).
// If an element is 0, then we cannot move through that element.
//
// Example 1:
// Input = {2,1,1,1,4}
// Output = 3
// Explanation: Starting from index '0', we can reach the last index through:
// 0->2->3->4
//
// Example 2:
// Input = {1,1,3,6,9,3,0,1,3}
// Output = 4
// Explanation: Starting from index '0', we can reach the last index through:
// 0->1->2->3->8

int count_min_jumps_recursive
(
    const int *jumps,
    int jumps_len,
    int current_index
)
{
    if (current_index == jumps_len - 1)
    {
        return 0;
    }

    if (jumps[current_index] == 0)
    {
        return INT_MAX;
    }

    int total_jumps = INT_MAX;
    int start = current_index + 1;
    int end = current_index + jumps[current_index];
    while (start < jumps_len && start <= end)
    {
        int min_jumps = count_min_jumps_recursive(jumps, jumps_len, start);
        if (min_jumps != INT_MAX && min_jumps + 1 < total_jumps)
        {
            total_jumps = min_jumps + 1;
        }
        start++;
    }
    return total_jumps;
}

int count_min_jumps
(
    const int *jumps,
    int jumps_len
)
{
    return count_min_jumps_recursive(jumps, jumps_len, 0);
}
