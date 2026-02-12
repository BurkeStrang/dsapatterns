package twoheaps

import (
	"container/heap"
)

// Interval struct represents an interval with a start and an end.
type Interval struct {
	Start, End int
}

// MaxHeap to create a max heap for start and end times.
type MaxHeapInterval struct {
	intervals []Interval
	isStart   bool
	indexes   []int
}

// Implement heap.Interface for MaxHeap.
func (h MaxHeapInterval) Len() int { return len(h.indexes) }

func (h MaxHeapInterval) Less(i, j int) bool {
	if h.isStart {
		return h.intervals[h.indexes[i]].Start > h.intervals[h.indexes[j]].Start
	}
	return h.intervals[h.indexes[i]].End > h.intervals[h.indexes[j]].End
}
func (h MaxHeapInterval) Swap(i, j int) { h.indexes[i], h.indexes[j] = h.indexes[j], h.indexes[i] }

func (h *MaxHeapInterval) Push(x interface{}) {
	h.indexes = append(h.indexes, x.(int))
}

func (h *MaxHeapInterval) Pop() interface{} {
	old := h.indexes
	n := len(old)
	x := old[n-1]
	h.indexes = old[0 : n-1]
	return x
}

// Solution struct as a substitute for a class in Java.
type IntervalSolution struct{}

func (s *IntervalSolution) findNextInterval(intervals []Interval) []int {
	n := len(intervals)
	maxStartHeap := &MaxHeapInterval{intervals: intervals, isStart: true, indexes: make([]int, 0, n)}
	maxEndHeap := &MaxHeapInterval{intervals: intervals, isStart: false, indexes: make([]int, 0, n)}
	result := make([]int, n)

	// Initialize heaps
	heap.Init(maxStartHeap)
	heap.Init(maxEndHeap)

	for i := range n {
		heap.Push(maxStartHeap, i)
		heap.Push(maxEndHeap, i)
	}

	// Iterate through intervals to find the next interval
	for range n {
		topEnd := heap.Pop(maxEndHeap).(int)
		result[topEnd] = -1 // Default to -1
		if intervals[maxStartHeap.indexes[0]].Start >= intervals[topEnd].End {
			topStart := heap.Pop(maxStartHeap).(int)
			for maxStartHeap.Len() > 0 && intervals[maxStartHeap.indexes[0]].Start >= intervals[topEnd].End {
				topStart = heap.Pop(maxStartHeap).(int)
			}
			result[topEnd] = topStart
			heap.Push(maxStartHeap, topStart) // Put it back as it could be next for other intervals
		}
	}
	return result
}
