package kwaymerge

import (
	"testing"
)

func Test_findKLargestPairs(t *testing.T) {
	tests := []struct {
		name  string
		nums1 []int
		nums2 []int
		k     int
		want  [][]int
	}{
		{name: "Example 1", nums1: []int{9, 8, 2}, nums2: []int{6, 3, 1}, k: 3, want: [][]int{{9, 3}, {8, 6}, {9, 6}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findKLargestPairs(tt.nums1, tt.nums2, tt.k)
			if !equal(got, tt.want) {
				t.Errorf("findKLargestPairs() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equal(a, b [][]int) bool {
	for i := range a {
		for j := range 2 {
			if a[i][j] != b[i][j] {
				return false
			}
		}
	}
	return true
}
