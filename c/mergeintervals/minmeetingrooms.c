#include "common/heap.h"

#include <stdlib.h>

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

typedef struct
{
    int start;
    int end;
} Meeting;

int compare_meeting_starts
(
    const void *a,
    const void *b
)
{
    const Meeting *x = a;
    const Meeting *y = b;
    return (x->start > y->start) - (x->start < y->start);
}

// orders the heap by meeting end time, earliest first
bool meeting_ends_first
(
    const void *a,
    const void *b
)
{
    return ((const Meeting *)a)->end < ((const Meeting *)b)->end;
}

int find_minimum_meeting_rooms
(
    Meeting *meetings,
    int meetings_len
)
{
    if (meetings_len == 0)
    {
        return 0;
    }

    // sort the meetings by start time
    qsort(meetings, (size_t)meetings_len, sizeof(Meeting),
          compare_meeting_starts);

    int min_rooms = 0;
    Heap min_heap = heap_new(sizeof(Meeting), meeting_ends_first);
    for (int i = 0; i < meetings_len; i++)
    {
        Meeting meeting = meetings[i];
        // remove all meetings that have ended
        while (min_heap.len > 0 &&
               meeting.start >= ((Meeting *)heap_top(&min_heap))->end)
        {
            heap_pop(&min_heap, NULL);
        }
        // add the current meeting into the min_heap
        heap_push(&min_heap, &meeting);
        // all active meeting are in the min_heap, so we need rooms for all of
        // them.
        if (min_heap.len > min_rooms)
        {
            min_rooms = min_heap.len;
        }
    }
    heap_free(&min_heap);
    return min_rooms;
}
