#include <algorithm>
#include <cstdlib>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

// Given a sorted number array and two integers ‘K’ and ‘X’,
// find ‘K’ closest numbers to ‘X’ in the array.
// Return the numbers in the sorted order.
// ‘X’ is not necessarily present in the array.
//
// Example 1:
// Input: [5, 6, 7, 8, 9], K = 3, X = 7
// Output: [6, 7, 8]
//
// Example 2:
// Input: [2, 4, 5, 6, 9], K = 3, X = 6
// Output: [4, 5, 6]
//
// Example 3:
// Input: [2, 4, 5, 6, 9], K = 3, X = 10
// Output: [5, 6, 9]

// binary_search returns the index of the target, or of the number closest to
// it from below when the target is not in the array
int binary_search(const std::vector<int> &arr, int target)
{
    int low = 0;
    int high = std::ssize(arr) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > 0)
    {
        return low - 1;
    }
    return low;
}

std::vector<int> find_closest_elements(const std::vector<int> &arr, int k,
                                       int x)
{
    int index = binary_search(arr, x);
    // 'low' should not be less than zero
    int low = std::max(index - k, 0);
    // 'high' should not be greater the size of the array
    int high = std::min(index + k, static_cast<int>(arr.size()) - 1);

    // a min heap of (absolute difference from 'x', index)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        min_heap;
    // add all candidate elements to the min heap, sorted by their absolute
    // difference from 'x'
    for (int i = low; i <= high; i++)
    {
        min_heap.push({std::abs(arr[i] - x), i});
    }

    // we need the top 'k' elements having the smallest difference from 'x'
    std::vector<int> result;
    for (int i = 0; i < k && !min_heap.empty(); i++)
    {
        result.push_back(arr[min_heap.top().second]);
        min_heap.pop();
    }

    std::ranges::sort(result);
    return result;
}
