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

func (this *Median) insertNum(num int) {
	if this.maxHeap.Len() == 0 || (*this.maxHeap).IntHeap[0] >= num {
		heap.Push(this.maxHeap, num)
	} else {
		heap.Push(this.minHeap, num)
	}

	if this.maxHeap.Len() > this.minHeap.Len()+1 {
		heap.Push(this.minHeap, heap.Pop(this.maxHeap))
	} else if this.maxHeap.Len() < this.minHeap.Len() {
		heap.Push(this.maxHeap, heap.Pop(this.minHeap))
	}
}

func (this *Median) findMedian() float64 {
	if this.maxHeap.Len() == this.minHeap.Len() {
		return float64((*this.maxHeap).IntHeap[0])/2.0 + float64((*this.minHeap)[0])/2.0
	}
	return float64((*this.maxHeap).IntHeap[0])
}
