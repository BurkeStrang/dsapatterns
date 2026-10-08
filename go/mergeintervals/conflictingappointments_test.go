package mergeintervals

import "testing"

func Test_canAttendAllAppointments(t *testing.T) {
	tests := []struct {
		name      string
		intervals []Interval
		want      bool
	}{
		{
			name:      "Example 1: overlapping intervals",
			intervals: []Interval{{1, 4}, {2, 5}, {7, 9}},
			want:      false,
		},
		{
			name:      "Example 2: non-overlapping intervals",
			intervals: []Interval{{6, 7}, {2, 4}, {13, 14}, {8, 12}, {45, 47}},
			want:      true,
		},
		{
			name:      "Example 3: overlapping intervals",
			intervals: []Interval{{4, 5}, {2, 3}, {3, 6}},
			want:      false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := canAttendAllAppointments(tt.intervals)
			if got != tt.want {
				t.Errorf("canAttendAllAppointments() = %v, want %v", got, tt.want)
			}
		})
	}
}
