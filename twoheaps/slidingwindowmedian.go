package twoheaps

import (
	"container/heap"
)

type Solution struct {
	maxH *MaxHeap
	minH *IntHeap
}

func (s *Solution) findSlidingWindowMedian(nums []int, k int) []float64 {
	result := make([]float64, len(nums)-k+1)
	s.maxH = &MaxHeap{IntHeap: make([]int, 0)}
	s.minH = &IntHeap{}

	for i := range nums {
		if s.maxH.Len() == 0 || s.maxH.IntHeap[0] >= nums[i] {
			heap.Push(s.maxH, nums[i])
		} else {
			heap.Push(s.minH, nums[i])
		}
		s.rebalanceHeaps()

		if i-k+1 >= 0 {
			if s.maxH.Len() == s.minH.Len() {
				result[i-k+1] = float64(s.maxH.IntHeap[0]+(*s.minH)[0]) / 2.0
			} else {
				result[i-k+1] = float64(s.maxH.IntHeap[0])
			}

			elementToBeRemoved := nums[i-k+1]
			if elementToBeRemoved <= s.maxH.IntHeap[0] {
				s.removeFromMaxHeap(elementToBeRemoved)
			} else {
				s.removeFromMinHeap(elementToBeRemoved)
			}
			s.rebalanceHeaps()
		}
	}

	return result
}

func (s *Solution) rebalanceHeaps() {
	if s.maxH.Len() > s.minH.Len()+1 {
		heap.Push(s.minH, heap.Pop(s.maxH))
	} else if s.maxH.Len() < s.minH.Len() {
		heap.Push(s.maxH, heap.Pop(s.minH))
	}
}

func (s *Solution) removeFromMaxHeap(target int) {
	for i := 0; i < len(s.maxH.IntHeap); i++ {
		if s.maxH.IntHeap[i] == target {
			heap.Remove(s.maxH, i)
			return
		}
	}
}

func (s *Solution) removeFromMinHeap(target int) {
	for i := 0; i < len(*s.minH); i++ {
		if (*s.minH)[i] == target {
			heap.Remove(s.minH, i)
			return
		}
	}
}
