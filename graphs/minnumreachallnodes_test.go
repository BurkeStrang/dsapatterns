package graphs

import "testing"

func Test_findSmallestSetOfVertices(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		n     int
		edges [][]int
		want  []int
	}{
		{
			name:  "Example 1",
			n:     6,
			edges: [][]int{{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}},
			want:  []int{0, 3},
		},
		{
			name:  "Single node",
			n:     1,
			edges: [][]int{},
			want:  []int{0},
		},
		{
			name:  "Disconnected nodes",
			n:     3,
			edges: [][]int{},
			want:  []int{0, 1, 2},
		},
		{
			name:  "All nodes connected in a chain",
			n:     4,
			edges: [][]int{{0, 1}, {1, 2}, {2, 3}},
			want:  []int{0},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSmallestSetOfVertices(tt.n, tt.edges)
			if !equalIntSlices(got, tt.want) {
				t.Errorf("findSmallestSetOfVertices() = %v, want %v", got, tt.want)
			}
		})
	}
}
