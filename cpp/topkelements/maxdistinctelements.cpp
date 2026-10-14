#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

// Given an array of numbers nums and an integer K,
// find the maximum number of distinct elements after removing exactly K
// elements from the nums array.
//
// Example 1:
// Input: nums = [7, 3, 5, 8, 5, 3, 3], K=2
// Expected Output: 3
// Explanation: We can remove two occurrences of 3 to be left with 3 distinct
// numbers [7, 3, 8],
// we have to skip 5 because it is not distinct and occurred twice.
// Another solution could be to remove one instance of '5' and '3' each to be
// left with three distinct numbers [7, 5, 8],
// in this case, we have to skip 3 because it occurred twice.
//
// Example 2:
// Input: [3, 5, 12, 11, 12], and K=3
// Expected Output: 2
// Explanation: We can remove one occurrence of 12, after which all numbers will
// become distinct.
// Then we can delete any two numbers which will leave us 2 distinct numbers in
// the result.
//
// Example 3:
// Input: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], and K=2
// Expected Output: 3
// Explanation: We can remove one occurrence of '4' to get three distinct
// numbers 1, 2 and 4.

int find_maximum_distinct_elements(const std::vector<int> &nums, int k)
{
    int distinct_elements_count = 0;

    // Find the frequency of each number
    std::unordered_map<int, int> num_frequency_map;
    for (int num : nums)
    {
        num_frequency_map[num]++;
    }

    // a min heap of the frequencies
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;

    // Insert all numbers with frequency greater than '1' into the min-heap
    for (auto [num, freq] : num_frequency_map)
    {
        if (freq == 1)
        {
            distinct_elements_count++;
        }
        else
        {
            min_heap.push(freq);
        }
    }

    // Following a greedy approach, try removing the least frequent numbers
    // first from the min-heap
    while (k > 0 && !min_heap.empty())
    {
        int frequency = min_heap.top();
        min_heap.pop();
        // To make an element distinct, we need to remove all of its
        // occurrences except one
        k -= frequency - 1;
        if (k >= 0)
        {
            distinct_elements_count++;
        }
    }

    // If k > 0, this means we have to remove some distinct numbers
    if (k > 0)
    {
        distinct_elements_count -= k;
    }

    return distinct_elements_count;
}
