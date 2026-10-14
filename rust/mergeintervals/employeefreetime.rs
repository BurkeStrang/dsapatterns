use std::cmp::Reverse;
use std::collections::BinaryHeap;

use super::shared::Interval;

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

/// One interval of one employee. The start time comes first so that the heap
/// orders by it; the two indices say where the interval sits in the schedule.
type EmployeeInterval = (i32, usize, usize);

pub fn find_employee_free_time(schedule: &[Vec<Interval>]) -> Vec<Interval> {
    let mut result = Vec::new();
    // BinaryHeap is a max heap, so wrap the items in Reverse to get a min heap
    let mut min_heap: BinaryHeap<Reverse<EmployeeInterval>> = BinaryHeap::new();

    // insert the first interval of each employee to the queue
    for i in 0..schedule.len() {
        min_heap.push(Reverse((schedule[i][0].start, i, 0)));
    }

    let Some(&Reverse((_, employee_index, _))) = min_heap.peek() else {
        return result;
    };
    let mut previous_interval = schedule[employee_index][0];
    while let Some(Reverse((_, employee_index, interval_index))) =
        min_heap.pop()
    {
        let employee_schedule = &schedule[employee_index];
        let interval = employee_schedule[interval_index];
        if previous_interval.end < interval.start {
            // if previous_interval is not overlapping with the next interval,
            // insert a free interval
            result.push(Interval {
                start: previous_interval.end,
                end: interval.start,
            });
            previous_interval = interval;
        } else if previous_interval.end < interval.end {
            // overlapping intervals, update the previous_interval if needed
            previous_interval = interval;
        }

        // if there are more intervals available for the same employee, add
        // their next interval
        if employee_schedule.len() > interval_index + 1 {
            min_heap.push(Reverse((
                employee_schedule[interval_index + 1].start,
                employee_index,
                interval_index + 1,
            )));
        }
    }

    result
}
