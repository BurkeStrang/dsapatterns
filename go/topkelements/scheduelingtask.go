package topkelements

import "container/heap"

// You are given a list of tasks that need to be run, in any order, on a server.
// Each task will take one CPU interval to execute but once a task has finished,
// it has a cooling period during which it can’t be run again.
// If the cooling period for all tasks is ‘K’ intervals,
// find the minimum number of CPU intervals that the server needs to finish all tasks.
// If at any time the server can’t execute any task then it must stay idle.
//
// Example 1:
// Input: [a, a, a, b, c, c], K=2
// Output: 7
// Explanation: a -> c -> b -> a -> c -> idle -> a
//
// Example 2:
// Input: [a, b, a], K=3
// Output: 5
// Explanation: a -> b -> idle -> idle -> a

func scheduleTasks(tasks []string, k int) int {
	intervalCount := 0
	taskFrequencyMap := make(map[string]int)

	for _, task := range tasks {
		taskFrequencyMap[task]++
	}

	maxHeap := &TaskHeap{}

	for task, frequency := range taskFrequencyMap {
		heap.Push(maxHeap, Task{task, frequency})
	}

	for maxHeap.Len() > 0 {
		waitList := []Task{}
		n := k + 1

		for n > 0 && maxHeap.Len() > 0 {
			intervalCount++
			task := heap.Pop(maxHeap).(Task)

			if task.frequency > 1 {
				task.frequency--
				waitList = append(waitList, task)
			}

			n--
		}

		for _, task := range waitList {
			heap.Push(maxHeap, task)
		}

		if maxHeap.Len() > 0 {
			intervalCount += n
		}
	}

	return intervalCount
}

type Task struct {
	task      string
	frequency int
}

type TaskHeap []Task

func (h TaskHeap) Len() int           { return len(h) }
func (h TaskHeap) Less(i, j int) bool { return h[i].frequency > h[j].frequency }
func (h TaskHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *TaskHeap) Push(x any) {
	*h = append(*h, x.(Task))
}

func (h *TaskHeap) Pop() any {
	old := *h
	n := len(old)
	task := old[n-1]
	*h = old[0 : n-1]
	return task
}
