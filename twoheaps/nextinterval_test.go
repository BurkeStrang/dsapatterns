package twoheaps

import (
	"testing"
)

func TestFindNextInterval(t *testing.T) {
	tests := []struct {
		name      string
		intervals []Interval
		want      []int
	}{
		{
			name:      "basic non-overlapping",
			intervals: []Interval{{2, 3}, {3, 4}, {5, 6}},
			want:      []int{1, 2, -1},
		},
		{
			name:      "overlapping intervals",
			intervals: []Interval{{3, 4}, {1, 5}, {4, 6}},
			want:      []int{2, -1, -1},
		},
		{
			name:      "single interval",
			intervals: []Interval{{1, 2}},
			want:      []int{-1},
		},
		{
			name:      "self as next interval",
			intervals: []Interval{{1, 1}, {3, 4}},
			want:      []int{0, -1},
		},
		{
			name:      "no next interval for identical",
			intervals: []Interval{{1, 2}, {1, 2}, {1, 2}},
			want:      []int{-1, -1, -1},
		},
		{
			name:      "start equals end",
			intervals: []Interval{{1, 2}, {2, 3}, {3, 4}},
			want:      []int{1, 2, -1},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := &IntervalSolution{}
			got := s.findNextInterval(tt.intervals)
			if len(got) != len(tt.want) {
				t.Fatalf("got %v, want %v", got, tt.want)
			}
			for i := range got {
				if got[i] != tt.want[i] {
					t.Errorf("result[%d] = %d, want %d", i, got[i], tt.want[i])
				}
			}
		})
	}
}
