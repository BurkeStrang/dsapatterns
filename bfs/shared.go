package bfs

import (
	"container/list"
	"errors"
)

// TreeNode struct
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
	Next  *TreeNode
}

// Custom Queue implementation
type Queue struct {
	data *list.List
}

func NewQueue() Queue {
	return Queue{data: list.New()}
}

func (q *Queue) Empty() bool {
	return q.data.Len() == 0
}

func (q *Queue) Front() (*TreeNode, error) {
	if q.Empty() {
		return nil, errors.New("queue is empty")
	}
	return q.data.Front().Value.(*TreeNode), nil
}

func (q *Queue) Push(value *TreeNode) {
	q.data.PushBack(value)
}

func (q *Queue) Pop() error {
	if q.Empty() {
		return errors.New("queue is empty")
	}
	q.data.Remove(q.data.Front())
	return nil
}



func equal(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if len(a[i]) != len(b[i]) {
			return false
		}
		for j := range a[i] {
			if a[i][j] != b[i][j] {
				return false
			}
		}
	}
	return true
}


func equalFloatSlices(a, b []float64) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if (a[i]-b[i]) > 1e-9 || (b[i]-a[i]) > 1e-9 {
			return false
		}
	}
	return true
}
