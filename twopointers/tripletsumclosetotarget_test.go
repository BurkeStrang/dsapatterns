package twopointers

import "testing"

func TestTripletSumCloseToTarget(t *testing.T) {
	tests := []struct {
		arr      []int
		target   int
		expected int
	}{
		{[]int{-1, 0, 2, 3}, 3, 2},
		{[]int{-3, -1, 1, 2}, 1, 0},
		{[]int{1, 0, 1, 1}, 100, 3},
		{[]int{0, 0, 1, 1, 2, 6}, 5, 4},
	}

	for _, tt := range tests {
		got := searchTriplet(tt.arr, tt.target)
		if got != tt.expected {
			t.Errorf("searchTriplet(%v, %d) = %d; want %d", tt.arr, tt.target, got, tt.expected)
		}
	}
}
