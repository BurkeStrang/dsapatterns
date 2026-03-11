package topkelements

import (
	"sort"
	"testing"
)

func Test_findKLargestNumbers(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		k    int
		want []int
	}{
		{name: "Example 1", nums: []int{3, 1, 5, 12, 2, 11}, k: 3, want: []int{5, 12, 11}},
		{name: "Example 2", nums: []int{5, 12, 11, -1, 12}, k: 3, want: []int{12, 11, 12}},
		{name: "All negative", nums: []int{-3, -1, -5, -12, -2, -11}, k: 3, want: []int{-1, -2, -3}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findKLargestNumbers(tt.nums, tt.k)
			if !sliceEqual(got, tt.want) {
				t.Errorf("findKLargestNumbers() = %v, want %v", got, tt.want)
			}
		})
	}
}

func sliceEqual(a, b []int) bool {
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
