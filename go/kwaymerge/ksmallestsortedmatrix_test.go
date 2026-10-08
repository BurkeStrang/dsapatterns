package kwaymerge

import "testing"

func Test_findKthSmallestPoint(t *testing.T) {
	tests := []struct {
		name   string
		matrix [][]int
		k      int
		want   int
	}{
		{name: "Example 1", matrix: [][]int{{2, 6, 8}, {3, 7, 10}, {5, 7, 8}}, k: 5, want: 7},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findKthSmallestPoint(tt.matrix, tt.k)
			if got != tt.want {
				t.Errorf("findKthSmallestPoint() = %v, want %v", got, tt.want)
			}
		})
	}
}
