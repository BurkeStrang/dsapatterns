#include <queue>
#include <utility>
#include <vector>

// Given an array of intervals, find the next interval of each interval. In a
// list of intervals, for an interval 'i' its next interval 'j' will have the
// smallest 'start' greater than or equal to the 'end' of 'i'.
//
// Write a function to return an array containing indices of the next interval
// of each input interval. If there is no next interval of a given interval,
// return -1. It is given that none of the intervals have the same start
// point.

struct Interval
{
    int start;
    int end;
};

std::vector<int> find_next_interval(const std::vector<Interval> &intervals)
{
    int n = std::ssize(intervals);
    // max-heaps of (start, index) and (end, index)
    std::priority_queue<std::pair<int, int>> max_start_heap;
    std::priority_queue<std::pair<int, int>> max_end_heap;
    std::vector<int> result(n, -1); // Default to -1

    // Initialize heaps
    for (int i = 0; i < n; i++)
    {
        max_start_heap.push({intervals[i].start, i});
        max_end_heap.push({intervals[i].end, i});
    }

    // Go through the intervals from the highest end to the lowest and find
    // the next interval of each
    while (!max_end_heap.empty())
    {
        auto [top_end, end_index] = max_end_heap.top();
        max_end_heap.pop();
        // find the interval that has the closest 'start'; the last one popped
        // here is the one with the smallest start that is still >= the end
        bool found = false;
        std::pair<int, int> top_start;
        while (!max_start_heap.empty() && max_start_heap.top().first >= top_end)
        {
            top_start = max_start_heap.top();
            found = true;
            max_start_heap.pop();
        }

        if (found)
        {
            result[end_index] = top_start.second;
            // put the interval back as it could be the next interval of other
            // intervals
            max_start_heap.push(top_start);
        }
    }

    return result;
}
