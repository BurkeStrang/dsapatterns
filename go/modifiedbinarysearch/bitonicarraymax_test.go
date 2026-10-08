package modifiedbinarysearch

import "testing"

func Test_findMaxInBitonicArray(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want int
	}{
		{name: "Example 1", arr: []int{1, 3, 8, 12, 4, 2}, want: 12},
		{name: "Example 2", arr: []int{3, 8, 3, 1}, want: 8},
		{name: "Example 3", arr: []int{1, 3, 8, 12}, want: 12},
		{name: "Example 4", arr: []int{10, 9, 8}, want: 10},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMaxInBitonicArray(tt.arr)
			if got != tt.want {
				t.Errorf("findMaxInBitonicArray() = %v, want %v", got, tt.want)
			}
		})
	}
}
