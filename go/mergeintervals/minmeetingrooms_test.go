package mergeintervals

import "testing"

func Test_findMinimumMeetingRooms(t *testing.T) {
	tests := []struct {
		name     string
		meetings []Meeting
		want     int
	}{
		{
			name:     "Example 1: overlapping meetings",
			meetings: []Meeting{{1, 4}, {2, 5}, {7, 9}},
			want:     2,
		},
		{
			name:     "Example 2: non-overlapping meetings",
			meetings: []Meeting{{6, 7}, {2, 4}, {8, 12}},
			want:     1,
		},
		{
			name:     "Example 3: overlapping meetings",
			meetings: []Meeting{{1, 4}, {2, 3}, {3, 6}},
			want:     2,
		},
		{
			name:     "Example 4: complex overlaps",
			meetings: []Meeting{{4, 5}, {2, 3}, {2, 4}, {3, 5}},
			want:     2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMinimumMeetingRooms(tt.meetings)
			if got != tt.want {
				t.Errorf("findMinimumMeetingRooms() = %v, want %v", got, tt.want)
			}
		})
	}
}
