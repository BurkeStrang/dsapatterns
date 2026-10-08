package topologicalsort

import (
	"sort"
	"testing"
)

func Test_topsort_sort(t *testing.T) {
	tests := []struct {
		name     string
		vertices int
		edges    [][]int
		want     []int
	}{
		{name: "Test Case 1", vertices: 6, edges: [][]int{{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}}, want: []int{5, 4, 2, 3, 1, 0}},
		{name: "Test Case 2", vertices: 4, edges: [][]int{{0, 1}, {1, 2}, {2, 3}}, want: []int{0, 1, 2, 3}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var s topsort
			got := s.sort(tt.vertices, tt.edges)
			if !equalSlices(got, tt.want) {
				t.Errorf("sort() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalSlices(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	sort.Ints(a)
	sort.Ints(b)
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
