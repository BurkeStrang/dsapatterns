package islandtraversal

import "testing"

func Test_findDistinctIslandsDFS(t *testing.T) {
	tests := []struct {
		name string
		matrix [][]int
		want   int
	}{
		{
			name: "two distinct islands",
			matrix: [][]int{
				{1, 1, 0, 0, 0},
				{1, 0, 0, 1, 1},
				{0, 0, 0, 1, 1},
			},
			want: 2,
		},
		{
			name: "all islands same shape",
			matrix: [][]int{
				{1, 0, 1, 0},
				{1, 0, 1, 0},
			},
			want: 1,
		},
		{
			name: "no islands",
			matrix: [][]int{
				{0, 0},
				{0, 0},
			},
			want: 0,
		},
		{
			name: "single island",
			matrix: [][]int{
				{1, 1},
				{1, 1},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findDistinctIslandsDFS(tt.matrix)
			if got != tt.want {
				t.Errorf("findDistinctIslandsDFS() = %v, want %v", got, tt.want)
			}
		})
	}
}

