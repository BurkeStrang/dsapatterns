package twopointers

import (
	"testing"
)

func TestFindNonDuplicates(t *testing.T) {
	tests := []struct {
		input    []int
		expected []int
		length   int
	}{
		{[]int{1, 1, 2}, []int{1, 2}, 2},
		{[]int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, []int{0, 1, 2, 3, 4}, 5},
		{[]int{1}, []int{1}, 1},
		{[]int{1, 2, 3}, []int{1, 2, 3}, 3},
	}

	for _, tt := range tests {
		arr := make([]int, len(tt.input))
		copy(arr, tt.input)
		got := moveElements(arr)
		if got != tt.length {
			t.Errorf("moveElements(%v) length = %d, want %d", tt.input, got, tt.length)
		}
		for i := range got {
			if arr[i] != tt.expected[i] {
				t.Errorf("moveElements(%v) arr[%d] = %d, want %d", tt.input, i, arr[i], tt.expected[i])
			}
		}
	}
}
