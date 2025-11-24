package islandtraversal

import "testing"

func Test_countIslands(t *testing.T) {
	tests := []struct {
		name string
		matrix [][]int
		want   int
	}{
		{
			name: "single island",
			matrix: [][]int{
				{1, 1, 0, 0},
				{1, 1, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1},
			},
			want: 3,
		},
		{
			name: "no islands",
			matrix: [][]int{
				{0, 0, 0},
				{0, 0, 0},
			},
			want: 0,
		},
		{
			name: "all land",
			matrix: [][]int{
				{1, 1},
				{1, 1},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countIslands(tt.matrix)
			if got != tt.want {
				t.Errorf("countIslands() = %v, want %v", got, tt.want)
			}
		})
	}
}

