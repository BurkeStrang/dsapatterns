#include <algorithm>
#include <functional>
#include <vector>

// Given an array of numbers and a number 'k', find the median of all the 'k'
// sized sub-arrays (or windows) of the array.
//
// Example 1:
// Input: nums=[1, 2, -1, 3, 5], k = 2
// Output: [1.5, 0.5, 1.0, 4.0]
//
// Example 2:
// Input: nums=[1, 2, -1, 3, 5], k = 3
// Output: [1.0, 2.0, 3.0]

// Heap is a binary heap that, unlike std::priority_queue, can remove a number
// from the middle; the sliding window needs that to drop the number going out.
// Compare is std::less<> for a max-heap and std::greater<> for a min-heap.
template <typename Compare> class Heap
{
  public:
    void push(int num)
    {
        items.push_back(num);
        std::ranges::push_heap(items, Compare{});
    }

    int pop()
    {
        std::ranges::pop_heap(items, Compare{});
        int top = items.back();
        items.pop_back();
        return top;
    }

    int top() const
    {
        return items.front();
    }

    int size() const
    {
        return std::ssize(items);
    }

    bool empty() const
    {
        return items.empty();
    }

    // remove takes one copy of num out of the heap
    void remove(int num)
    {
        auto it = std::ranges::find(items, num);
        if (it != items.end())
        {
            items.erase(it);
            std::ranges::make_heap(items, Compare{});
        }
    }

  private:
    std::vector<int> items;
};

struct Window
{
    // the smaller half of the window, largest on top
    Heap<std::less<>> max_heap;
    // the larger half of the window, smallest on top
    Heap<std::greater<>> min_heap;

    void rebalance_heaps()
    {
        // either both the heaps will have equal number of elements or
        // max-heap will have one more element than the min-heap
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.pop());
        }
        else if (max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.pop());
        }
    }
};

std::vector<double> find_sliding_window_median(const std::vector<int> &nums,
                                               int k)
{
    std::vector<double> result;
    Window window;
    for (int i = 0; i < std::ssize(nums); i++)
    {
        if (window.max_heap.empty() || window.max_heap.top() >= nums[i])
        {
            window.max_heap.push(nums[i]);
        }
        else
        {
            window.min_heap.push(nums[i]);
        }
        window.rebalance_heaps();

        // if we have at least 'k' elements in the sliding window
        if (i - k + 1 >= 0)
        {
            // add the median to the result
            int max_top = window.max_heap.top();
            if (window.max_heap.size() == window.min_heap.size())
            {
                // we have even number of elements, take the average of middle
                // two elements
                result.push_back((max_top + window.min_heap.top()) / 2.0);
            }
            else
            {
                // because max-heap will have one more element than the
                // min-heap
                result.push_back(max_top);
            }

            // remove the element going out of the sliding window
            int element_to_be_removed = nums[i - k + 1];
            if (element_to_be_removed <= max_top)
            {
                window.max_heap.remove(element_to_be_removed);
            }
            else
            {
                window.min_heap.remove(element_to_be_removed);
            }
            window.rebalance_heaps();
        }
    }
    return result;
}
