#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>

// Given ‘M’ sorted arrays, find the smallest range that includes at least one
// number from each of the ‘M’ lists.
// Example 1:
// Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
// Output: [4, 7]
// Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
//
// Example 2:
// Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
// Output: [9, 12]
// Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3

std::vector<int> find_smallest_range(const std::vector<std::vector<int>> &lists)
{
    // a min heap of (number, array index, element index); tuples compare
    // field by field, so the smallest number is on top
    using Entry = std::tuple<int, int, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<>> min_heap;

    int range_start = 0;
    int range_end = INT_MAX;
    int current_max_number = INT_MIN;

    // put the 1st element of each array in the min heap
    for (int i = 0; i < std::ssize(lists); i++)
    {
        if (!lists[i].empty())
        {
            min_heap.push({lists[i][0], i, 0});
            current_max_number = std::max(current_max_number, lists[i][0]);
        }
    }

    // take the smallest (top) element form the min heap, if it gives us
    // smaller range, update the ranges; if the array of the top element has
    // more elements, insert the next element in the heap.
    // we stop as soon as one of the arrays has run out, the heap then holds
    // fewer numbers than there are arrays
    while (min_heap.size() == lists.size())
    {
        auto [num, array_index, element_index] = min_heap.top();
        min_heap.pop();
        // widen to long long, the gap between the starting ends overflows an
        // int
        long long current_range =
            static_cast<long long>(range_end) - range_start;
        if (current_range > static_cast<long long>(current_max_number) - num)
        {
            range_start = num;
            range_end = current_max_number;
        }

        element_index++;
        if (element_index < std::ssize(lists[array_index]))
        {
            int next = lists[array_index][element_index];
            min_heap.push({next, array_index, element_index});
            current_max_number = std::max(current_max_number, next);
        }
    }

    return {range_start, range_end};
}
