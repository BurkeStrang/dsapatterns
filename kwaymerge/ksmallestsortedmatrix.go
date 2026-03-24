package kwaymerge

// Given an N * N matrix where each row and column is sorted in ascending order,
// find the Kth smallest element in the matrix.
// Example 1:
// Input: Matrix=[
//     [2, 6, 8],
//     [3, 7, 10],
//     [5, 8, 11]
//   ],
//   K=5
// Output: 7
// Explanation: The 5th smallest number in the matrix is 7.

import (
	"container/heap"
)

// Node structure
type Point struct {
	Row, Col int
}

// PriorityQueue implements heap.Interface and holds Nodes
type PriorityQueue []*Point

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].Row < pq[j].Row || (pq[i].Row == pq[j].Row && pq[i].Col < pq[j].Col)
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	item := x.(*Point)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// findKthSmallest finds the Kth smallest element in a matrix
func findKthSmallestPoint(matrix [][]int, k int) int {
	minHeap := &PriorityQueue{}
	heap.Init(minHeap)

	// put the 1st element of each row in the min heap
	// we don't need to push more than 'k' elements in the heap
	for i := 0; i < len(matrix) && i < k; i++ {
		heap.Push(minHeap, &Point{i, 0})
	}

	// take the smallest (top) element form the min heap, if the running count is equal
	// to k return the number. if the row of the top element has more elements, add the
	// next element to the heap
	numberCount, result := 0, 0
	for minHeap.Len() > 0 {
		node := heap.Pop(minHeap).(*Point)
		result = matrix[node.Row][node.Col]
		if numberCount++; numberCount == k {
			break
		}
		node.Col++
		if len(matrix[0]) > node.Col {
			heap.Push(minHeap, node)
		}
	}
	return result
}
