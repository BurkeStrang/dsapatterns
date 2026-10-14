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

import { Heap } from "../common/heap.ts";
import type { Interval } from "./shared.ts";

// one interval of one employee: where it sits in the schedule, and its start
// time, which the heap orders by
interface EmployeeInterval {
  start: number;
  employeeIndex: number;
  intervalIndex: number;
}

export function findEmployeeFreeTime(schedule: Interval[][]): Interval[] {
  const result: Interval[] = [];
  const minHeap = new Heap<EmployeeInterval>((a, b) => a.start < b.start);

  // insert the first interval of each employee to the queue
  schedule.forEach((employeeSchedule, i) => {
    minHeap.push({
      start: employeeSchedule[0].start,
      employeeIndex: i,
      intervalIndex: 0,
    });
  });

  const first = minHeap.peek();
  if (first === undefined) {
    return result;
  }
  let previousInterval = schedule[first.employeeIndex][0];
  for (let top = minHeap.pop(); top !== undefined; top = minHeap.pop()) {
    const { employeeIndex, intervalIndex } = top;
    const employeeSchedule = schedule[employeeIndex];
    const interval = employeeSchedule[intervalIndex];
    if (previousInterval.end < interval.start) {
      // if previousInterval is not overlapping with the next interval,
      // insert a free interval
      result.push({ start: previousInterval.end, end: interval.start });
      previousInterval = interval;
    } else if (previousInterval.end < interval.end) {
      // overlapping intervals, update the previousInterval if needed
      previousInterval = interval;
    }

    // if there are more intervals available for the same employee, add
    // their next interval
    if (employeeSchedule.length > intervalIndex + 1) {
      minHeap.push({
        start: employeeSchedule[intervalIndex + 1].start,
        employeeIndex,
        intervalIndex: intervalIndex + 1,
      });
    }
  }
  return result;
}
