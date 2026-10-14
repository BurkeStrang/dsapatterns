#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

// Given an unsorted array of numbers,
// find the top ‘K’ frequently occurring numbers in it.
//
// Example 1:
// Input: [1, 3, 5, 12, 11, 12, 11], K = 2
// Output: [12, 11]
// Explanation: Both '11' and '12' appeared twice.
//
// Example 2:
// Input: [5, 12, 11, 3, 11], K = 2
// Output: [11, 5] or [11, 12] or [11, 3]
// Explanation: Only '11' appeared twice; all other numbers appeared once.

std::vector<int> find_top_k_frequent_numbers(const std::vector<int> &nums,
                                             int k)
{
    // Find the frequency of each number
    std::unordered_map<int, int> num_frequency_map;
    for (int n : nums)
    {
        num_frequency_map[n]++;
    }

    // Create a min heap to store (frequency, number) entries
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        min_freq_heap;

    // Go through all numbers in num_frequency_map and push them into the
    // min heap. If the heap size is more than k, remove the smallest (top)
    // entry
    for (auto [num, frequency] : num_frequency_map)
    {
        min_freq_heap.push({frequency, num});
        if (std::ssize(min_freq_heap) > k)
        {
            min_freq_heap.pop();
        }
    }

    // Create a list of top k frequent numbers; the heap gives the least
    // frequent first, so fill the list from the back
    std::vector<int> top_numbers(min_freq_heap.size());
    for (int i = std::ssize(top_numbers) - 1; i >= 0; i--)
    {
        top_numbers[i] = min_freq_heap.top().second;
        min_freq_heap.pop();
    }

    return top_numbers;
}
