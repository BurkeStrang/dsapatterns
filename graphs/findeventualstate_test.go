package graphs

import "testing"

func Test_eventualSafeNodes(t *testing.T) {
	tests := []struct {
		name  string
		graph [][]int
		want  []int
	}{
		{
			name:  "Example 1: [3,4,5,6]",
			graph: [][]int{{1, 2}, {2, 3}, {2}, {}, {5}, {6}, {}},
			want:  []int{3, 4, 5, 6},
		},
		{
			name:  "Example 2: [2,4,5,6]",
			graph: [][]int{{1, 2}, {2, 3}, {5}, {0}, {}, {}, {4}},
			want:  []int{2, 4, 5, 6},
		},
		{
			name:  "Example 3: [0,1,2,3,4]",
			graph: [][]int{{1, 2, 3}, {2, 3}, {3}, {}, {0, 1, 2}},
			want:  []int{0, 1, 2, 3, 4},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := eventualSafeNodes(tt.graph)
			if !equalIntSlices(got, tt.want) {
				t.Errorf("eventualSafeNodes() = %v, want %v", got, tt.want)
			}
		})
	}
}

