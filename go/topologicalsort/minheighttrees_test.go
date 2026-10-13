package topologicalsort

import "testing"

func Test_findTrees(t *testing.T) {
	tests := []struct {
		name  string
		nodes int
		edges [][]int
		want  []int
	}{
		{name: "Example 1", nodes: 5, edges: [][]int{{0, 1}, {1, 2}, {1, 3}, {2, 4}}, want: []int{1, 2}},
		{name: "Example 2", nodes: 4, edges: [][]int{{0, 1}, {0, 2}, {2, 3}}, want: []int{0, 2}},
		{name: "Example 3", nodes: 4, edges: [][]int{{0, 1}, {1, 2}, {1, 3}}, want: []int{1}},
		{name: "Star", nodes: 4, edges: [][]int{{1, 0}, {1, 2}, {1, 3}}, want: []int{1}},
		{name: "Two centres", nodes: 6, edges: [][]int{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}, want: []int{3, 4}},
		{name: "One node", nodes: 1, edges: [][]int{}, want: []int{0}},
		{name: "No nodes", nodes: 0, edges: [][]int{}, want: []int{}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findTrees(tt.nodes, tt.edges)
			// the roots can come back in any order
			if !equalSlices(got, tt.want) {
				t.Errorf("findTrees() = %v, want %v", got, tt.want)
			}
		})
	}
}
