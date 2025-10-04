package mergeintervals

import (
	"container/heap"
)

// For ‘K’ employees, we are given a list of intervals representing each employee’s working hours.
// Our goal is to determine if there is a free interval which is common to all employees.
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

// EmployeeInterval struct representing an employee's working interval
type EmployeeInterval struct {
	interval      *Interval
	employeeIndex int
	intervalIndex int
}

// EmployeeIntervalHeap type for priority queue
type EmployeeIntervalHeap []*EmployeeInterval

func (h EmployeeIntervalHeap) Len() int           { return len(h) }
func (h EmployeeIntervalHeap) Less(i, j int) bool { return h[i].interval.Start < h[j].interval.Start }
func (h EmployeeIntervalHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *EmployeeIntervalHeap) Push(x any) {
	*h = append(*h, x.(*EmployeeInterval))
}

func (h *EmployeeIntervalHeap) Pop() any {
	old := *h
	n := len(old)
	item := old[n-1]
	*h = old[0 : n-1]
	return item
}

func findEmployeeFreeTime(schedule [][]*Interval) []*Interval {
	var result []*Interval
	minHeap := &EmployeeIntervalHeap{}
	heap.Init(minHeap)

	// insert the first interval of each employee to the queue
	for i := range schedule {
		heap.Push(minHeap, &EmployeeInterval{schedule[i][0], i, 0})
	}

	previousInterval := minHeap.Top().interval
	for minHeap.Len() > 0 {
		queueTop := heap.Pop(minHeap).(*EmployeeInterval)
		// if previousInterval is not overlapping with the next interval, insert a free interval
		if previousInterval.End < queueTop.interval.Start {
			result = append(result, &Interval{previousInterval.End, queueTop.interval.Start})
			previousInterval = queueTop.interval
		} else { // overlapping intervals, update the previousInterval if needed
			if previousInterval.End < queueTop.interval.End {
				previousInterval = queueTop.interval
			}
		}

		// if there are more intervals available for the same employee, add their next interval
		employeeSchedule := schedule[queueTop.employeeIndex]
		if len(employeeSchedule) > queueTop.intervalIndex+1 {
			heap.Push(minHeap, &EmployeeInterval{employeeSchedule[queueTop.intervalIndex+1], queueTop.employeeIndex, queueTop.intervalIndex + 1})
		}
	}

	return result
}

// Top returns the top element of the heap without removing it
func (h *EmployeeIntervalHeap) Top() *EmployeeInterval {
	return (*h)[0]
}
