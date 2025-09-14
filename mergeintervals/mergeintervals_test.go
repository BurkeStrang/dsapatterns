package mergeintervals

import "testing"

func Test_merge(t *testing.T) {
	tests := []struct {
		name      string
		intervals []Interval
		want      []Interval
	}{
		{
			name:      "Example 1",
			intervals: []Interval{{1, 4}, {2, 5}, {7, 9}},
			want:      []Interval{{1, 5}, {7, 9}},
		},
		{
			name:      "Example 2",
			intervals: []Interval{{6, 7}, {2, 4}, {5, 9}},
			want:      []Interval{{2, 4}, {5, 9}},
		},
		{
			name:      "Example 3",
			intervals: []Interval{{1, 4}, {2, 6}, {3, 5}},
			want:      []Interval{{1, 6}},
		},
		{
			name:      "No overlap",
			intervals: []Interval{{1, 2}, {3, 4}, {5, 6}},
			want:      []Interval{{1, 2}, {3, 4}, {5, 6}},
		},
		{
			name:      "Single interval",
			intervals: []Interval{{1, 10}},
			want:      []Interval{{1, 10}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := merge(tt.intervals)
			if !equalIntervals(got, tt.want) {
				t.Errorf("merge() = %v, want %v", got, tt.want)
			}
		})
	}
}


func equalIntervals(a, b []Interval) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
