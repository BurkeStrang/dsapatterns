"""
For ‘K’ employees, we are given a list of intervals representing each
employee’s working hours.
Our goal is to determine if there is a free interval which is common to all
employees.

Example 1:
Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
Output: [3,5]
Explanation: All the employees are free between [3,5].

Example 2:
Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
Explanation: All employees are free between [4,6] and [8,9].

Example 3:
Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
Output: [5,7]
Explanation: All employees are free between [5,7].
"""

import heapq

from mergeintervals.shared import Interval


def find_employee_free_time(schedule: list[list[Interval]]) -> list[Interval]:
    result: list[Interval] = []
    # one interval of one employee: the start time comes first so that the
    # heap orders by it; the two indices say where the interval sits in the
    # schedule
    min_heap: list[tuple[int, int, int]] = []
    # insert the first interval of each employee to the queue
    for i, employee_schedule in enumerate(schedule):
        heapq.heappush(min_heap, (employee_schedule[0].start, i, 0))
    if not min_heap:
        return result

    previous_interval = schedule[min_heap[0][1]][0]
    while min_heap:
        _, employee_index, interval_index = heapq.heappop(min_heap)
        employee_schedule = schedule[employee_index]
        interval = employee_schedule[interval_index]
        if previous_interval.end < interval.start:
            # if previous_interval is not overlapping with the next interval,
            # insert a free interval
            result.append(Interval(previous_interval.end, interval.start))
            previous_interval = interval
        elif previous_interval.end < interval.end:
            # overlapping intervals, update the previous_interval if needed
            previous_interval = interval

        # if there are more intervals available for the same employee, add
        # their next interval
        if len(employee_schedule) > interval_index + 1:
            heapq.heappush(
                min_heap,
                (
                    employee_schedule[interval_index + 1].start,
                    employee_index,
                    interval_index + 1,
                ),
            )
    return result
