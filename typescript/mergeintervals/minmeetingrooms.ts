// Given a list of intervals representing the start and end time of ‘N’
// meetings,
// find the minimum number of rooms required to hold all the meetings.
//
// Example 1:
// Meetings: [[1,4], [2,5], [7,9]]
// Output: 2
// Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these
// two meetings.
// [7,9] can occur in any of the two rooms later.
//
// Example 2:
// Meetings: [[6,7], [2,4], [8,12]]
// Output: 1
// Explanation: None of the meetings overlap,
// therefore we only need one room to hold all meetings.
//
// Example 3:
// Meetings: [[1,4], [2,3], [3,6]]
// Output:2
// Explanation: Since [1,4] overlaps with the other two meetings [2,3] and
// [3,6],
// we need two rooms to hold all the meetings.
//
// Example 4:
// Meetings: [[4,5], [2,3], [2,4], [3,5]]
// Output: 2
// Explanation: We will need one room for [2,3] and [3,5],
// and another room for [2,4] and [4,5].
//
// Constraints:
// 1 <= meetings.length <= 104
// 0 <= starti < endi <= 106

import { Heap } from "../common/heap.ts";

export interface Meeting {
  start: number;
  end: number;
}

export function findMinimumMeetingRooms(meetings: Meeting[]): number {
  // sort the meetings by start time
  meetings.sort((a, b) => a.start - b.start);

  let minRooms = 0;
  // a min heap of the end times of the meetings that are going on
  const minHeap = new Heap<number>((a, b) => a < b);
  for (const meeting of meetings) {
    // remove all meetings that have ended
    let earliestEnd = minHeap.peek();
    while (earliestEnd !== undefined && meeting.start >= earliestEnd) {
      minHeap.pop();
      earliestEnd = minHeap.peek();
    }
    // add the current meeting into the minHeap
    minHeap.push(meeting.end);
    // all active meeting are in the minHeap, so we need rooms for all of
    // them.
    minRooms = Math.max(minRooms, minHeap.size);
  }
  return minRooms;
}
