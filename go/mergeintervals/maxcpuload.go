package mergeintervals

import (
	"container/heap"
	"sort"
)

// We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.
//
// Example 1:
// Jobs: [[1,4,3], [2,5,4], [7,9,6]]
// Output: 7
// Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the jobs are running at the same time i.e., during the time interval (2,4).
//
// Example 2:
// Jobs: [[6,7,10], [2,4,11], [8,12,15]]
// Output: 15
// Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15.
//
// Example 3:
// Jobs: [[1,4,2], [2,4,1], [3,6,5]]
// Output: 8
// Explanation: Maximum CPU load will be 8 as all jobs overlap during the time interval [3,4].

type Job struct {
	Start   int
	End     int
	CPULoad int
}

type PriorityQueue []*Job

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].End < pq[j].End
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	*pq = append(*pq, x.(*Job))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func findMaxCPULoad(jobs []*Job) int {
	sort.Slice(jobs, func(i, j int) bool {
		return jobs[i].Start < jobs[j].Start
	})

	maxCPULoad := 0
	currentCPULoad := 0
	minHeap := &PriorityQueue{}
	heap.Init(minHeap)

	for _, job := range jobs {
		// remove all jobs that have ended
		for minHeap.Len() > 0 && job.Start > (*minHeap)[0].End {
			currentCPULoad -= heap.Pop(minHeap).(*Job).CPULoad
		}

		// add the current job into the minHeap
		heap.Push(minHeap, job)
		currentCPULoad += job.CPULoad
		maxCPULoad = max(maxCPULoad, currentCPULoad)
	}
	return maxCPULoad
}
