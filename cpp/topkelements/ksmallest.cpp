#include <queue>
#include <vector>

// Given an unsorted array of numbers, find Kth smallest number in it.
// Please note that it is the Kth smallest number in the sorted order,
// not the Kth distinct element.
// Note: For a detailed discussion about different approaches to solve this
// problem,
// take a look at Kth Smallest Number.
//
// Example 1:
// Input: [1, 5, 12, 2, 11, 5], K = 3
// Output: 5
// Explanation: The 3rd smallest number is '5', as the first two smaller numbers
// are [1, 2].
//
// Example 2:
// Input: [1, 5, 12, 2, 11, 5], K = 4
// Output: 5
// Explanation: The 4th smallest number is '5', as the first three small numbers
// are [1, 2, 5].
//
// Example 3:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: 11
// Explanation: The 3rd smallest number is '11', as the first two small numbers
// are [5, -1].

int find_kth_smallest_number(const std::vector<int> &nums, int k)
{
    // a max heap of the 'k' smallest numbers seen so far
    std::priority_queue<int> max_heap;

    // put first k numbers in the max heap
    for (int i = 0; i < k; i++)
    {
        max_heap.push(nums[i]);
    }

    // go through the remaining numbers of the array, if the number from the
    // array is smaller than the top (biggest) number of the heap, remove the
    // top number from heap and add the number from array
    for (int i = k; i < std::ssize(nums); i++)
    {
        if (nums[i] < max_heap.top())
        {
            max_heap.pop();
            max_heap.push(nums[i]);
        }
    }

    // the root of the heap has the Kth smallest number
    return max_heap.top();
}
