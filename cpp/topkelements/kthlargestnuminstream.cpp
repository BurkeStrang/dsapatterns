#include <functional>
#include <queue>
#include <vector>

// Design a class to efficiently find the Kth largest element in a stream of
// numbers.
// The class should have the following two things:
// The constructor of the class should accept an integer array containing
// initial numbers from the stream and an integer ‘K’.
// The class should expose a function add(int num) which will store the given
// number and return the Kth largest number.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 4
// 1. Calling add(6) should return '5'.
// 2. Calling add(13) should return '6'.
// 2. Calling add(4) should still return '6'.

class KthLargest
{
  public:
    KthLargest(const std::vector<int> &nums, int k_value) : k(k_value)
    {
        for (int num : nums)
        {
            add(num);
        }
    }

    int add(int num)
    {
        min_heap.push(num);

        if (std::ssize(min_heap) > k)
        {
            min_heap.pop();
        }

        return min_heap.top();
    }

  private:
    // a min heap holding the 'k' largest numbers seen so far
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
    int k; // The value of 'k'
};
