package mergeintervals

import "testing"

func Test_intersectingIntervals(t *testing.T) {
	tests := []struct {
		name string
		arr1 []Interval
		arr2 []Interval
		want []Interval
	}{
		{
			name: "Example 1",
			arr1: []Interval{{1, 3}, {5, 6}, {7, 9}},
			arr2: []Interval{{2, 3}, {5, 7}},
			want: []Interval{{2, 3}, {5, 6}, {7, 7}},
		},
		{
			name: "Example 2",
			arr1: []Interval{{1, 3}, {5, 7}, {9, 12}},
			arr2: []Interval{{5, 10}},
			want: []Interval{{5, 7}, {9, 10}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := intersectingIntervals(tt.arr1, tt.arr2)
			if !equalIntervals(got, tt.want) {
				t.Errorf("intersectingIntervals() = %v, want %v", got, tt.want)
			}
		})
	}
}
