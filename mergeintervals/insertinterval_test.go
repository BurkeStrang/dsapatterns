package mergeintervals

import "testing"

func Test_insert(t *testing.T) {
	tests := []struct {
		name string
		intervals   []Interval
		newInterval Interval
		want        []Interval
	}{
		{
			name:        "Example 1",
			intervals:   []Interval{{1, 3}, {5, 7}, {8, 12}},
			newInterval: Interval{4, 6},
			want:        []Interval{{1, 3}, {4, 7}, {8, 12}},
		},
		{
			name:        "Example 2",
			intervals:   []Interval{{1, 3}, {5, 7}, {8, 12}},
			newInterval: Interval{4, 10},
			want:        []Interval{{1, 3}, {4, 12}},
		},
		{
			name:        "Example 3",
			intervals:   []Interval{{2, 3}, {5, 7}},
			newInterval: Interval{1, 4},
			want:        []Interval{{1, 4}, {5, 7}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := insert(tt.intervals, tt.newInterval)
			if !equalIntervals(got,tt.want) {
				t.Errorf("insert() = %v, want %v", got, tt.want)
			}
		})
	}
}

