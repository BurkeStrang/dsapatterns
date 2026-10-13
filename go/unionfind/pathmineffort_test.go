package unionfind

import "testing"

func Test_minimumEffortPath(t *testing.T) {
	tests := []struct {
		name    string
		heights [][]int
		want    int
	}{
		{name: "Example 1", heights: [][]int{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}}, want: 1},
		{name: "Example 2", heights: [][]int{{1, 2, 2}, {3, 3, 3}, {5, 3, 1}}, want: 2},
		{name: "Example 3", heights: [][]int{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, want: 0},
		{name: "One cell", heights: [][]int{{7}}, want: 0},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := minimumEffortPath(tt.heights)
			if got != tt.want {
				t.Errorf("minimumEffortPath() = %v, want %v", got, tt.want)
			}
		})
	}
}
