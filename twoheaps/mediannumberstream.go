package twoheaps

import (
	"container/heap"
)

// An IntHeap is a min-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// An MaxHeap is a max-heap of ints.
type MaxHeap struct {
	IntHeap
}

func (h MaxHeap) Less(i, j int) bool { return h.IntHeap[i] > h.IntHeap[j] }

type Median struct {
	maxHeap *MaxHeap
	minHeap *IntHeap
}

func Constructor() Median {
	return Median{
		maxHeap: &MaxHeap{IntHeap: make([]int, 0)},
		minHeap: &IntHeap{},
	}
}

func (median *Median) insertNum(num int) {
	if median.maxHeap.Len() == 0 || (*median.maxHeap).IntHeap[0] >= num {
		heap.Push(median.maxHeap, num)
	} else {
		heap.Push(median.minHeap, num)
	}

	if median.maxHeap.Len() > median.minHeap.Len()+1 {
		heap.Push(median.minHeap, heap.Pop(median.maxHeap))
	} else if median.maxHeap.Len() < median.minHeap.Len() {
		heap.Push(median.maxHeap, heap.Pop(median.minHeap))
	}
}

func (median *Median) findMedian() float64 {
	if median.maxHeap.Len() == median.minHeap.Len() {
		return float64((*median.maxHeap).IntHeap[0])/2.0 + float64((*median.minHeap)[0])/2.0
	}
	return float64((*median.maxHeap).IntHeap[0])
}
