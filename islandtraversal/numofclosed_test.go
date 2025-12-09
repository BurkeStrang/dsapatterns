package islandtraversal

import (
	"testing"
)

func Test_countClosedIslands(t *testing.T) {
	tests := []struct {
		name   string
		matrix [][]int
		want   int
	}{
		{
			name: "one simple closed island",
			matrix: [][]int{
				{1, 1, 1, 1, 1},
				{1, 0, 0, 0, 1},
				{1, 0, 1, 0, 1},
				{1, 0, 0, 0, 1},
				{1, 1, 1, 1, 1},
			},
			want: 1,
		},
		{
			name: "two closed islands",
			matrix: [][]int{
				{1, 1, 0, 1, 0, 0},
				{1, 0, 1, 0, 0, 0},
				{1, 0, 1, 0, 1, 0},
				{1, 1, 0, 1, 0, 0},
			},
			want: 2,
		},
		{
			name: "islands touching border are NOT closed",
			matrix: [][]int{
				{0, 1, 1, 1},
				{1, 0, 0, 1},
				{1, 1, 0, 1},
				{1, 1, 1, 1},
			},
			// top-left 0 touches border → not closed
			// the connected 0's form one island, but it's open
			want: 0,
		},
		{
			name: "no land at all",
			matrix: [][]int{
				{1, 1, 1},
				{1, 1, 1},
				{1, 1, 1},
			},
			want: 0,
		},
		{
			name: "all land but touches border (so zero)",
			matrix: [][]int{
				{0, 0, 0},
				{0, 0, 0},
				{0, 0, 0},
			},
			want: 0,
		},
		{
			name: "complex inner islands but with border openings",
			matrix: [][]int{
				{1, 1, 1, 1, 1, 1},
				{1, 0, 0, 0, 0, 1},
				{1, 0, 1, 0, 0, 1},
				{0, 0, 0, 0, 1, 1}, // leftmost 0 touches border → not closed
				{1, 1, 1, 1, 1, 1},
			},
			// open island on the left invalidates that region
			// right-side island is fully surrounded → 1 closed
			want: 1,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countClosedIslands(copyMatrix(tt.matrix))
			if got != tt.want {
				t.Errorf("countClosedIslands() = %v, want %v", got, tt.want)
			}
		})
	}
}

