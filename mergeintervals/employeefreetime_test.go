package mergeintervals

import "testing"

func Test_findEmployeeFreeTime(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		schedule [][]*Interval
		want     []*Interval
	}{
		{
			name: "Example 1: two employees, one free interval",
			schedule: [][]*Interval{
				{{Start: 1, End: 3}, {Start: 5, End: 6}},
				{{Start: 2, End: 3}, {Start: 6, End: 8}},
			},
			want: []*Interval{{Start: 3, End: 5}},
		},
		{
			name: "Example 2: three employees, two free intervals",
			schedule: [][]*Interval{
				{{Start: 1, End: 3}, {Start: 9, End: 12}},
				{{Start: 2, End: 4}},
				{{Start: 6, End: 8}},
			},
			want: []*Interval{{Start: 4, End: 6}, {Start: 8, End: 9}},
		},
		{
			name: "Example 3: three employees, one free interval",
			schedule: [][]*Interval{
				{{Start: 1, End: 3}},
				{{Start: 2, End: 4}},
				{{Start: 3, End: 5}, {Start: 7, End: 9}},
			},
			want: []*Interval{{Start: 5, End: 7}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findEmployeeFreeTime(tt.schedule)
			if !intervalsEqual(got, tt.want) {
				t.Errorf("findEmployeeFreeTime() = %v, want %v", got, tt.want)
			}
		})
	}
}

func intervalsEqual(a, b []*Interval) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i].Start != b[i].Start || a[i].End != b[i].End {
			return false
		}
	}
	return true
}
