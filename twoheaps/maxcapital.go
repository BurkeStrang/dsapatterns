package twoheaps

import "container/heap"

// capitalHeap is a min-heap of project indices sorted by capital requirement.
type capitalHeap struct {
	indices []int
	capital []int
}

func (h capitalHeap) Len() int           { return len(h.indices) }
// this is a min-heap, so Less returns true if capital at i is less than capital at j
func (h capitalHeap) Less(i, j int) bool { return h.capital[h.indices[i]] < h.capital[h.indices[j]] }
func (h capitalHeap) Swap(i, j int)      { h.indices[i], h.indices[j] = h.indices[j], h.indices[i] }
func (h *capitalHeap) Push(x any)        { h.indices = append(h.indices, x.(int)) }
func (h *capitalHeap) Pop() any {
	old := h.indices
	n := len(old)
	x := old[n-1]
	h.indices = old[:n-1]
	return x
}

// profitHeap is a max-heap of project indices sorted by profit.
type profitHeap struct {
	indices []int
	profits []int
}

func (h profitHeap) Len() int           { return len(h.indices) }
// this is a max-heap, so Less returns true if profit at i is greater than profit at j
func (h profitHeap) Less(i, j int) bool { return h.profits[h.indices[i]] > h.profits[h.indices[j]] }
func (h profitHeap) Swap(i, j int)      { h.indices[i], h.indices[j] = h.indices[j], h.indices[i] }
func (h *profitHeap) Push(x any)        { h.indices = append(h.indices, x.(int)) }
func (h *profitHeap) Pop() any {
	old := h.indices
	n := len(old)
	x := old[n-1]
	h.indices = old[:n-1]
	return x
}

func findMaximumCapital(capitalArr, profitsArr []int, numberOfProjects, initialCapital int) int {
	n := len(profitsArr)
	minCapitalHeap := &capitalHeap{capital: capitalArr}
	maxProfitHeap := &profitHeap{profits: profitsArr}

	// insert all project indices into the min-capital heap
	for i := range n {
		heap.Push(minCapitalHeap, i)
	}

	// try to find a total of 'numberOfProjects' best projects
	availableCapital := initialCapital
	for range numberOfProjects {
		// move all affordable projects into the max-profit heap
		for minCapitalHeap.Len() > 0 && capitalArr[minCapitalHeap.indices[0]] <= availableCapital {
			heap.Push(maxProfitHeap, heap.Pop(minCapitalHeap))
		}

		// no affordable project found
		if maxProfitHeap.Len() == 0 {
			break
		}

		// select the project with the maximum profit
		availableCapital += profitsArr[heap.Pop(maxProfitHeap).(int)]
	}

	return availableCapital
}
