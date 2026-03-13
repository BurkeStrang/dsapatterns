package topkelements

import "testing"

func Test_findKthSmallestNumber(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		k    int
		want int
	}{
		{name: "Example 1", nums: []int{1, 5, 12, 2, 11, 5}, k: 3, want: 5},
		{name: "Example 2", nums: []int{1, 5, 12, 2, 11, 5}, k: 4, want: 5},
		{name: "Example 3", nums: []int{5, 12, 11, -1, 12}, k: 3, want: 11},
		{name: "Example 4", nums: []int{1, 5, 12, 2, 11, 5}, k: 1, want: 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findKthSmallestNumber(tt.nums, tt.k)
			if got != tt.want {
				t.Errorf("findKthSmallestNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}

