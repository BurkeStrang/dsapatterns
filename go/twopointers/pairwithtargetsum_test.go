package twopointers

import (
	"testing"
)

func TestPairWithTargetSum(t *testing.T) {
	tests := []struct {
		arr      []int
		target   int
		expected []int
	}{
		{[]int{1, 2, 3, 4, 6}, 6, []int{1, 3}},
		{[]int{2, 5, 9, 11}, 11, []int{0, 2}},
		{[]int{1, 2, 3, 4, 5}, 10, []int{-1, -1}},
	}

	for _, tt := range tests {
		result := search(tt.arr, tt.target)
		if result[0] != tt.expected[0] || result[1] != tt.expected[1] {
			t.Errorf("pairWithTargetSum(%v, %d) = %v; want %v", tt.arr, tt.target, result, tt.expected)
		}
	}
}
