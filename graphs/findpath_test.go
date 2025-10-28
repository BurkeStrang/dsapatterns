package graphs

import "testing"

func Test_validPath(t *testing.T) {
	tests := []struct {
		name  string
		n     int
		edges [][]int
		start int
		end   int
		want  bool
	}{
		{
			name:  "path exists simple",
			n:     4,
			edges: [][]int{{0, 1}, {1, 2}, {2, 3}},
			start: 0,
			end:   3,
			want:  true,
		},
		{
			name:  "no path between disconnected components",
			n:     4,
			edges: [][]int{{0, 1}, {2, 3}},
			start: 0,
			end:   3,
			want:  false,
		},
		{
			name:  "no path with isolated nodes",
			n:     5,
			edges: [][]int{{0, 1}, {3, 4}},
			start: 0,
			end:   4,
			want:  false,
		},
		{
			name:  "single node graph",
			n:     1,
			edges: [][]int{},
			start: 0,
			end:   0,
			want:  true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := validPath(tt.n, tt.edges, tt.start, tt.end)
			if got != tt.want {
				t.Errorf("validPath() = %v, want %v", got, tt.want)
			}
		})
	}
}
