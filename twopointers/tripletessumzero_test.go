package twopointers

import (
	"reflect"
	"sort"
	"testing"
)

func sortTriplets(triplets [][]int) {
	for _, t := range triplets {
		sort.Ints(t)
	}
	sort.Slice(triplets, func(i, j int) bool {
		for k := range 3 {
			if triplets[i][k] != triplets[j][k] {
				return triplets[i][k] < triplets[j][k]
			}
		}
		return false
	})
}

func TestTripletsSumZero(t *testing.T) {
	tests := []struct {
		input    []int
		expected [][]int
	}{
		{
			input:    []int{-3, 0, 1, 2, -1, 1, -2},
			expected: [][]int{{-3, 1, 2}, {-2, 0, 2}, {-2, 1, 1}, {-1, 0, 1}},
		},
		{
			input:    []int{-5, 2, -1, -2, 3},
			expected: [][]int{{-5, 2, 3}, {-2, -1, 3}},
		},
		{
			input:    []int{1, 2, 3},
			expected: [][]int{},
		},
	}

	for _, tt := range tests {
		got := searchTriplets(tt.input)
		sortTriplets(got)
		sortTriplets(tt.expected)
		if !reflect.DeepEqual(got, tt.expected) {
			t.Errorf("searchTriplets(%v) = %v, want %v", tt.input, got, tt.expected)
		}
	}
}
