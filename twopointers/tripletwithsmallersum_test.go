package twopointers

import "testing"

func TestFindTriplets(t *testing.T) {
	tests := []struct {
		arr      []int
		target   int
		expected int
	}{
		{[]int{-1, 0, 2, 3}, 3, 2},
		{[]int{-1, 4, 2, 1, 3}, 5, 4},
		{[]int{}, 5, 0},
		{[]int{1, 2}, 3, 0},
	}

	for _, tt := range tests {
		result := findTriplets(tt.arr, tt.target)
		if result != tt.expected {
			t.Errorf("findTriplets(%v, %d) = %d; want %d", tt.arr, tt.target, result, tt.expected)
		}
	}
}
