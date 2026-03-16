package topkelements

import "testing"

func Test_findMaximumDistinctElements(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		k    int
		want int
	}{
		{name: "Example 1", nums: []int{7, 3, 5, 8, 5, 3, 3}, k: 2, want: 3},
		{name: "Example 2", nums: []int{3, 5, 12, 11, 12}, k: 3, want: 2},
		{name: "Example 3", nums: []int{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, k: 2, want: 3},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMaximumDistinctElements(tt.nums, tt.k)
			if got != tt.want {
				t.Errorf("findMaximumDistinctElements() = %v, want %v", got, tt.want)
			}
		})
	}
}
