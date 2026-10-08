package bitwisexor

import "testing"

func Test_flipAndInvertImage(t *testing.T) {
	tests := []struct {
		name string
		arr  [][]int
		want [][]int
	}{
		{name: "Example 1", arr: [][]int{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}}, want: [][]int{{0, 1, 0}, {0, 0, 0}, {0, 0, 1}}},
		{name: "Example 2", arr: [][]int{{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}}, want: [][]int{{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}}},
		{name: "Single row", arr: [][]int{{1, 0, 0, 1}}, want: [][]int{{0, 1, 1, 0}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := flipAndInvertImage(tt.arr)
			if !sliceEqual2D(got, tt.want) {
				t.Errorf("flipAndInvertImage() = %v, want %v", got, tt.want)
			}
		})
	}
}

func sliceEqual2D(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		for j := range a[i] {
			if a[i][j] != b[i][j] {
				return false
			}
		}
	}
	return true
}
