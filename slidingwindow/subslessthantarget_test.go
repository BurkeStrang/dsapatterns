package slidingwindow

import "testing"

func Test_findSubarrays(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		arr    []int
		target int
		want   [][]int
	}{
		{
			name:   "Example 1",
			arr:    []int{2, 5, 3, 10},
			target: 30,
			want: [][]int{
				{2}, {2, 5}, {5}, {5, 3}, {3}, {10},
			},
		},
		{
			name:   "Example 2",
			arr:    []int{8, 2, 6, 5},
			target: 50,
			want: [][]int{
				{8}, {8, 2}, {2}, {2, 6}, {6}, {6, 5}, {5},
			},
		},
		{
			name:   "Target 0",
			arr:    []int{10, 5, 2, 6},
			target: 0,
			want:   [][]int{},
		},
		{
			name:   "Single element < target",
			arr:    []int{1},
			target: 2,
			want:   [][]int{{1}},
		},
		{
			name:   "Single element >= target",
			arr:    []int{5},
			target: 5,
			want:   [][]int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSubarrays(tt.arr, tt.target)
			if !equalSlices(got, tt.want) {
				t.Errorf("findSubarrays() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalSlices(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}
	used := make([]bool, len(b))
	for _, x := range a {
		found := false
		for j, y := range b {
			if !used[j] && equalIntSlices(x, y) {
				used[j] = true
				found = true
				break
			}
		}
		if !found {
			return false
		}
	}
	return true
}
