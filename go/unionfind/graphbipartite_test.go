package unionfind

import "testing"

func Test_isBipartite(t *testing.T) {
	tests := []struct {
		name  string
		graph [][]int
		want  bool
	}{
		{name: "Example 1", graph: [][]int{{1, 3}, {0, 2}, {1, 3}, {0, 2}}, want: true},
		{name: "Example 2", graph: [][]int{{1}, {0}, {3}, {2}}, want: true},
		{name: "Example 3", graph: [][]int{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}, want: false},
		{name: "No edges", graph: [][]int{{}, {}, {}}, want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isBipartite(tt.graph)
			if got != tt.want {
				t.Errorf("isBipartite() = %v, want %v", got, tt.want)
			}
		})
	}
}
