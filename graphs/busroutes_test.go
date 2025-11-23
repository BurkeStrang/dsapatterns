package graphs

import "testing"

func Test_numBusesToDestination(t *testing.T) {
	tests := []struct {
		name string
		routes [][]int
		source int
		target int
		want   int
	}{
		{
			name:   "example 1",
			routes: [][]int{{1, 2, 7}, {3, 6, 7}},
			source: 1,
			target: 6,
			want:   2,
		},
		{
			name:   "example 2",
			routes: [][]int{{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}},
			source: 15,
			target: 12,
			want:   -1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := numBusesToDestination(tt.routes, tt.source, tt.target)
			if got != tt.want {
				t.Errorf("numBusesToDestination() = %v, want %v", got, tt.want)
			}
		})
	}
}
