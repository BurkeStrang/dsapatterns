package islandtraversal

import "testing"

func Test_maxAreaOfIsland(t *testing.T) {
	tests := []struct {
		name   string
		matrix [][]int
		want   int
	}{
		{
			name: "single island",
			matrix: [][]int{
				{0, 1, 0, 0},
				{1, 1, 0, 0},
				{0, 0, 1, 1},
				{0, 0, 1, 1},
			},
			want: 4,
		},
		{
			name: "no island",
			matrix: [][]int{
				{0, 0, 0},
				{0, 0, 0},
			},
			want: 0,
		},
		{
			name: "multiple islands",
			matrix: [][]int{
				{1, 0, 0, 1},
				{0, 1, 1, 0},
				{0, 0, 0, 1},
			},
			want: 2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxAreaOfIsland(tt.matrix)
			if tt.want != got {
				t.Errorf("maxAreaOfIsland() = %v, want %v", got, tt.want)
			}
		})
	}
}
