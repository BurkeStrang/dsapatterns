package twopointers

import (
	"reflect"
	"testing"
)

func TestSquareSortedArray(t *testing.T) {
	tests := []struct {
		input    []int
		expected []int
	}{
		{input: []int{-2, -1, 0, 2, 3}, expected: []int{0, 1, 4, 4, 9}},
		{input: []int{-3, -1, 0, 1, 2}, expected: []int{0, 1, 1, 4, 9}},
		{input: []int{0}, expected: []int{0}},
		{input: []int{-1}, expected: []int{1}},
		{input: []int{1, 2, 3}, expected: []int{1, 4, 9}},
		{input: []int{-4, -3, -2, -1}, expected: []int{1, 4, 9, 16}},
	}

	for _, tt := range tests {
		result := makeSquares(tt.input)
		if !reflect.DeepEqual(result, tt.expected) {
			t.Errorf("makeSquares(%v) = %v; want %v", tt.input, result, tt.expected)
		}
	}
}
