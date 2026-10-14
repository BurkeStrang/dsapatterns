#include "mergeintervals/shared.hpp"

#include <functional>
#include <queue>
#include <tuple>
#include <vector>

// For ‘K’ employees, we are given a list of intervals representing each
// employee’s working hours.
// Our goal is to determine if there is a free interval which is common to all
// employees.
//
// Example 1:
// Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
// Output: [3,5]
// Explanation: All the employees are free between [3,5].
//
// Example 2:
// Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
// Output: [4,6], [8,9]
// Explanation: All employees are free between [4,6] and [8,9].
//
// Example 3:
// Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
// Output: [5,7]
// Explanation: All employees are free between [5,7].

std::vector<Interval>
find_employee_free_time(const std::vector<std::vector<Interval>> &schedule)
{
    std::vector<Interval> result;
    // one interval of one employee: the start time comes first so that the
    // heap orders by it; the two indices say where the interval sits in the
    // schedule
    using EmployeeInterval = std::tuple<int, int, int>;
    // std::greater turns the priority queue into a min heap
    std::priority_queue<EmployeeInterval, std::vector<EmployeeInterval>,
                        std::greater<>>
        min_heap;

    // insert the first interval of each employee to the queue
    for (int i = 0; i < std::ssize(schedule); i++)
    {
        min_heap.push({schedule[i][0].start, i, 0});
    }

    if (min_heap.empty())
    {
        return result;
    }
    Interval previous_interval = schedule[std::get<1>(min_heap.top())][0];
    while (!min_heap.empty())
    {
        auto [start, employee_index, interval_index] = min_heap.top();
        min_heap.pop();
        const std::vector<Interval> &employee_schedule =
            schedule[employee_index];
        Interval interval = employee_schedule[interval_index];
        if (previous_interval.end < interval.start)
        {
            // if previous_interval is not overlapping with the next interval,
            // insert a free interval
            result.push_back({previous_interval.end, interval.start});
            previous_interval = interval;
        }
        else if (previous_interval.end < interval.end)
        {
            // overlapping intervals, update the previous_interval if needed
            previous_interval = interval;
        }

        // if there are more intervals available for the same employee, add
        // their next interval
        if (std::ssize(employee_schedule) > interval_index + 1)
        {
            min_heap.push({employee_schedule[interval_index + 1].start,
                           employee_index, interval_index + 1});
        }
    }

    return result;
}
