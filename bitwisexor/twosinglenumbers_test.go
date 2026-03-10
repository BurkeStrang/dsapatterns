package bitwisexor

import (
	"sort"
	"testing"
)

func Test_findSingleNumbers(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want []int
	}{
		{name: "Example 1", nums: []int{1, 4, 2, 1, 3, 5, 6, 2, 3, 5}, want: []int{4, 6}},
		{name: "Example 2", nums: []int{2, 1, 3, 2}, want: []int{1, 3}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSingleNumbers(tt.nums)
			if !sliceEqual(got, tt.want) {
				t.Errorf("findSingleNumbers() = %v, want %v", got, tt.want)
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
