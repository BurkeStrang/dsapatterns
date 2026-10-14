package topkelements

import (
	"slices"
	"testing"
)

func Test_findClosestElements(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		K    int
		X    int
		want []int
	}{
		{name: "Example 1", arr: []int{5, 6, 7, 8, 9}, K: 3, X: 7, want: []int{6, 7, 8}},
		{name: "Example 2", arr: []int{2, 4, 5, 6, 9}, K: 3, X: 6, want: []int{4, 5, 6}},
		{name: "Example 3", arr: []int{2, 4, 5, 6, 9}, K: 3, X: 10, want: []int{5, 6, 9}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findClosestElements(tt.arr, tt.K, tt.X)
			if !slices.Equal(got, tt.want) {
				t.Errorf("findClosestElements() = %v, want %v", got, tt.want)
			}
		})
	}
}
