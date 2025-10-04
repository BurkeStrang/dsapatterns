package mergeintervals

import (
	"container/heap"
	"sort"
)

// Given a list of intervals representing the start and end time of ‘N’ meetings,
// find the minimum number of rooms required to hold all the meetings.
//
// Example 1:
// Meetings: [[1,4], [2,5], [7,9]]
// Output: 2
// Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings.
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
// Explanation: Since [1,4] overlaps with the other two meetings [2,3] and [3,6],
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


type Meeting struct {
	Start int
	End   int
}

// A slice of Meetings that implements heap.Interface
type MeetingHeap []Meeting

func (h MeetingHeap) Len() int           { return len(h) }
func (h MeetingHeap) Less(i, j int) bool { return h[i].End < h[j].End }
func (h MeetingHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MeetingHeap) Push(x any) {
	*h = append(*h, x.(Meeting))
}

func (h *MeetingHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func findMinimumMeetingRooms(meetings []Meeting) int {
	if len(meetings) == 0 {
		return 0
	}

	// sort the meetings by start time
	sort.Slice(meetings, func(i, j int) bool {
		return meetings[i].Start < meetings[j].Start
	})

	minRooms := 0
	minHeap := &MeetingHeap{}
	heap.Init(minHeap)
	for _, meeting := range meetings {
		// remove all meetings that have ended
		for minHeap.Len() > 0 && meeting.Start >= (*minHeap)[0].End {
			heap.Pop(minHeap)
		}
		// add the current meeting into the minHeap
		heap.Push(minHeap, meeting)
		// all active meeting are in the minHeap, so we need rooms for all of them.
		if minHeap.Len() > minRooms {
			minRooms = minHeap.Len()
		}
	}
	return minRooms
}
