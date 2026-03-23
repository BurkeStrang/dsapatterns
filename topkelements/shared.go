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

// MaxCharHeap

type MaxCharHeap []CharFreq

type CharFreq struct {
	Letter    rune
	Frequency int
}

func (h MaxCharHeap) Len() int           { return len(h) }
func (h MaxCharHeap) Less(i, j int) bool { return h[i].Frequency > h[j].Frequency }
func (h MaxCharHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxCharHeap) Push(x any) {
	*h = append(*h, x.(CharFreq))
}

func (h *MaxCharHeap) Pop() any {
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

// MinFreqHeap

type Entry struct {
	Num       int
	Frequency int
}
type MinFreqHeap []Entry

func (h MinFreqHeap) Len() int           { return len(h) }
func (h MinFreqHeap) Less(i, j int) bool { return h[i].Frequency < h[j].Frequency }
func (h MinFreqHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinFreqHeap) Push(x any) {
	*h = append(*h, x.(Entry))
}

func (h *MinFreqHeap) Pop() any {
	old := *h
	n := len(old)
	entry := old[n-1]
	*h = old[:n-1]
	return entry
}

// MinClosestHeap

type ClosestEntry struct {
	key   int
	value int
}

type MinClosestHeap []*ClosestEntry

func (h MinClosestHeap) Len() int           { return len(h) }
func (h MinClosestHeap) Less(i, j int) bool { return h[i].key < h[j].key }
func (h MinClosestHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinClosestHeap) Push(x any) {
	*h = append(*h, x.(*ClosestEntry))
}

func (h *MinClosestHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
