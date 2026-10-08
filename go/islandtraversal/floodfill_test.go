package islandtraversal

import (
	"reflect"
	"testing"
)

func Test_floodFill(t *testing.T) {
	tests := []struct {
		name     string
		matrix   [][]int
		x        int
		y        int
		newColor int
		want     [][]int
	}{
		{
			name: "basic flood fill",
			matrix: [][]int{
				{1, 1, 1},
				{1, 1, 0},
				{1, 0, 1},
			},
			x:        1,
			y:        1,
			newColor: 2,
			want: [][]int{
				{2, 2, 2},
				{2, 2, 0},
				{2, 0, 1},
			},
		},
		{
			name: "starting point already new color",
			matrix: [][]int{
				{0, 0},
				{0, 1},
			},
			x:        1,
			y:        1,
			newColor: 1,
			want: [][]int{
				{0, 0},
				{0, 1},
			},
		},
		{
			name: "no fill when starting outside bounds",
			matrix: [][]int{
				{1, 1},
				{1, 1},
			},
			x:        3, // outside grid
			y:        0,
			newColor: 5,
			want: [][]int{
				{1, 1},
				{1, 1},
			},
		},
		{
			name: "single cell matrix",
			matrix: [][]int{
				{1},
			},
			x:        0,
			y:        0,
			newColor: 9,
			want: [][]int{
				{9},
			},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {

			// Copy matrix to avoid modifying shared test cases
			input := copyMatrix(tt.matrix)

			got := floodFill(input, tt.x, tt.y, tt.newColor)

			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("floodFill() = %v, want %v", got, tt.want)
			}
		})
	}
}
