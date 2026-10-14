#include <functional>
#include <queue>
#include <vector>

// Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]
//
// Example 2:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: [12, 11, 12]

// find_k_largest_numbers - keeps all comments same and method name same
std::vector<int> find_k_largest_numbers(const std::vector<int> &nums, int k)
{
    // std::greater turns the priority queue into a min heap
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;

    // put first 'K' numbers in the min heap
    for (int i = 0; i < k; i++)
    {
        min_heap.push(nums[i]);
    }

    // go through the remaining numbers of the array, if the number from the
    // array is bigger than the top (smallest) number of the min-heap, remove
    // the top number from heap and add the number from array
    for (int i = k; i < std::ssize(nums); i++)
    {
        if (nums[i] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    // the heap has the top 'K' numbers, return them in a list
    std::vector<int> result;
    while (!min_heap.empty())
    {
        result.push_back(min_heap.top());
        min_heap.pop();
    }
    return result;
}
