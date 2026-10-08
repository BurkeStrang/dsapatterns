package slidingwindow

import "testing"

func Test_findSubarrayCount(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		nums   []int
		target int
		want   int
	}{
		{"Example 1", []int{2, 5, 3, 10}, 30, 6},
		{"Example 2", []int{8, 2, 6, 5}, 50, 7},
		{"Example 3 (target 0)", []int{10, 5, 2, 6}, 0, 0},
		{"Single element < target", []int{1}, 2, 1},
		{"Single element >= target", []int{5}, 5, 0},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSubarrayCount(tt.nums, tt.target)
			if got != tt.want {
				t.Errorf("findSubarrayCount() = %v, want %v", got, tt.want)
			}
		})
	}
}
