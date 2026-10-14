#include <functional>
#include <queue>
#include <vector>

// Design a class to calculate the median of a number stream. The class should
// have the following two methods:
//
// insert_num(num): stores the number in the class
// find_median(): returns the median of all numbers inserted in the class
//
// If the count of numbers inserted in the class is even, the median will be
// the average of the middle two numbers.

class Median
{
  public:
    void insert_num(int num)
    {
        if (max_heap.empty() || max_heap.top() >= num)
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }

        // either both the heaps will have equal number of elements or
        // max-heap will have one more element than the min-heap
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (max_heap.size() < min_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double find_median() const
    {
        if (max_heap.size() == min_heap.size())
        {
            // we have even number of elements, take the average of middle two
            // elements
            return max_heap.top() / 2.0 + min_heap.top() / 2.0;
        }
        // because max-heap will have one more element than the min-heap
        return max_heap.top();
    }

  private:
    // the smaller half of the numbers, largest on top
    std::priority_queue<int> max_heap;
    // the larger half of the numbers, smallest on top
    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
};
