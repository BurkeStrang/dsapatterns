package topkelements

// Design a class that simulates a Stack data structure,
// implementing the following two operations:
//
// push(int num): Pushes the number ‘num’ on the stack.
// pop(): Returns the most frequent number in the stack.
// If there is a tie, return the number which was pushed later.
//
// Example:
// After following push operations: push(1), push(2), push(3), push(2), push(1), push(2), push(5)
// 1. pop() should return 2, as it is the most frequent number
// 2. Next pop() should return 1
// 3. Next pop() should return 2

import (
	"container/heap"
)

type Element struct {
	number         int
	frequency      int
	sequenceNumber int
}

type ElementHeap []Element

func (h ElementHeap) Len() int { return len(h) }
func (h ElementHeap) Less(i, j int) bool {
	return h[i].frequency > h[j].frequency || (h[i].frequency == h[j].frequency && h[i].sequenceNumber > h[j].sequenceNumber)
}
func (h ElementHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *ElementHeap) Push(x any) {
	*h = append(*h, x.(Element))
}

func (h *ElementHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type Solution struct {
	sequenceNumber int
	maxHeap        ElementHeap
	frequencyMap   map[int]int
}

func Construct() Solution {
	return Solution{
		sequenceNumber: 0,
		maxHeap:        make(ElementHeap, 0),
		frequencyMap:   make(map[int]int),
	}
}

func (s *Solution) Push(num int) {
	s.frequencyMap[num]++
	heap.Push(&s.maxHeap, Element{number: num, frequency: s.frequencyMap[num], sequenceNumber: s.sequenceNumber})
	s.sequenceNumber++
}

func (s *Solution) Pop() int {
	top := heap.Pop(&s.maxHeap).(Element)
	num := top.number

	if s.frequencyMap[num] > 1 {
		s.frequencyMap[num]--
	} else {
		delete(s.frequencyMap, num)
	}

	return num
}
