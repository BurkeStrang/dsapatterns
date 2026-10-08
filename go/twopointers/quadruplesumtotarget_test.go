package twopointers

import (
	"reflect"
	"sort"
	"testing"
)

func sortQuadruplets(q [][]int) {
	for _, quad := range q {
		sort.Ints(quad)
	}
	sort.Slice(q, func(i, j int) bool {
		for k := range 4 {
			if quad := q[i][k] - q[j][k]; quad != 0 {
				return quad < 0
			}
		}
		return false
	})
}

func TestSearchQuadruplets(t *testing.T) {
	tests := []struct {
		arr      []int
		target   int
		expected [][]int
	}{
		{
			arr:    []int{4, 1, 2, -1, 1, -3},
			target: 1,
			expected: [][]int{
				{-3, -1, 1, 4},
				{-3, 1, 1, 2},
			},
		},
		{
			arr:    []int{2, 0, -1, 1, -2, 2},
			target: 2,
			expected: [][]int{
				{-2, 0, 2, 2},
				{-1, 0, 1, 2},
			},
		},
	}

	for _, tt := range tests {
		result := searchQuadruplets(tt.arr, tt.target)
		sortQuadruplets(result)
		sortQuadruplets(tt.expected)
		if !reflect.DeepEqual(result, tt.expected) {
			t.Errorf("searchQuadruplets(%v, %d) = %v; want %v", tt.arr, tt.target, result, tt.expected)
		}
	}
}
