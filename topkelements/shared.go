package topkelements

import "fmt"

// MinHeap
type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

// MaxHeap
type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}

// MaxPointHeap

type Point struct {
	X int
	Y int
}

func (p *Point) String() string {
	return fmt.Sprintf("(%d,%d)", p.X, p.Y)
}

func NewPoint(x, y int) *Point {
	return &Point{X: x, Y: y}
}

func (p *Point) DistFromOrigin() int {
	// ignoring sqrt
	return (p.X * p.X) + (p.Y * p.Y)
}

type MaxPointHeap []*Point

func (h MaxPointHeap) Len() int           { return len(h) }
func (h MaxPointHeap) Less(i, j int) bool { return h[i].DistFromOrigin() > h[j].DistFromOrigin() }
func (h MaxPointHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxPointHeap) Push(x any) {
	*h = append(*h, x.(*Point))
}

func (h *MaxPointHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}
