package islandtraversal

import "testing"

func Test_findIslandPerimeter(t *testing.T) {
	tests := []struct {
		name   string
		matrix [][]int
		want   int
	}{
		{
			name: "simple square island",
			matrix: [][]int{
				{0, 1, 0},
				{1, 1, 1},
				{0, 1, 0},
			},
			// shape is a plus sign → perimeter = 12
			want: 12,
		},
		{
			name: "single land cell",
			matrix: [][]int{
				{1},
			},
			want: 4,
		},
		{
			name: "single row island",
			matrix: [][]int{
				{1, 1, 1, 1},
			},
			// 4 cells in a row = 2 exposed edges per cell + 2 ends = 2+2+2+2 = 8
			want: 10, // Correct perimeter: ends (3 sides + 3 sides) + middle (2 + 2)
		},
		{
			name: "one big solid block",
			matrix: [][]int{
				{1, 1},
				{1, 1},
			},
			// 2x2 block perimeter = 8
			want: 8,
		},
		{
			name: "L-shaped island",
			matrix: [][]int{
				{1, 0},
				{1, 1},
			},
			// Shape:
			// 1 .
			// 1 1
			// Perimeter = 8
			want: 8,
		},
		{
			name: "island touching border",
			matrix: [][]int{
				{1, 1, 0},
				{1, 0, 0},
				{1, 1, 1},
			},
			// Count exposed edges manually → perimeter = 14
			want: 14,
		},
		{
			name: "island with a hole inside",
			matrix: [][]int{
				{1, 1, 1},
				{1, 0, 1},
				{1, 1, 1},
			},
			// A hollow square → perimeter counts both outer and inner edges
			// outer = 12, inner hole = 4 → total = 16
			want: 16,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findIslandPerimeter(copyMatrix(tt.matrix))
			if got != tt.want {
				t.Errorf("findIslandPerimeter() = %v, want %v", got, tt.want)
			}
		})
	}
}
