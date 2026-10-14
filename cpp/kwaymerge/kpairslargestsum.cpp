#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

// Given two sorted arrays in descending order,
// find ‘K’ pairs with the largest sum where each pair consists of numbers from
// both the arrays.
//
// Example 1:
// Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
// Output: [9, 3], [9, 6], [8, 6]
// Explanation: These 3 pairs have the largest sum. No other pair has a sum
// larger than any of these.
//
// Example 2:
// Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
// Output: [5, 2], [5, -1], [2, 2]

// find_k_largest_pairs finds k largest pairs.
std::vector<std::vector<int>>
find_k_largest_pairs(const std::vector<int> &nums1,
                     const std::vector<int> &nums2, int k)
{
    // a min heap of (sum of the pair, the pair), so the pair with the
    // smallest sum is on top
    using Entry = std::pair<int, std::pair<int, int>>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<>> min_heap;

    int n1 = std::min(k, static_cast<int>(nums1.size()));
    int n2 = std::min(k, static_cast<int>(nums2.size()));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            int sum = nums1[i] + nums2[j];
            if (std::ssize(min_heap) < k)
            {
                min_heap.push({sum, {nums1[i], nums2[j]}});
                continue;
            }

            // if the sum of the two numbers from the two arrays is smaller
            // than the smallest (top) element of the heap, we can 'break'
            // here.
            if (sum < min_heap.top().first)
            {
                break;
            }

            // we've a pair with a larger sum, remove top and insert this pair
            // in heap
            min_heap.pop();
            min_heap.push({sum, {nums1[i], nums2[j]}});
        }
    }

    std::vector<std::vector<int>> result;
    while (!min_heap.empty())
    {
        auto [first, second] = min_heap.top().second;
        result.push_back({first, second});
        min_heap.pop();
    }
    return result;
}
