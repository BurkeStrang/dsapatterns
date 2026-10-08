package monotonicstack

import "testing"

func Test_dailyTemperatures(t *testing.T) {
	tests := []struct {
		name         string
		temperatures []int
		want         []int
	}{
		{
			name:         "Example 1",
			temperatures: []int{70, 73, 75, 71, 69, 72, 76, 73},
			want:         []int{1, 1, 4, 2, 1, 1, 0, 0},
		},
		{
			name:         "Example 2",
			temperatures: []int{73, 72, 71, 70},
			want:         []int{0, 0, 0, 0},
		},
		{
			name:         "Example 3",
			temperatures: []int{70, 71, 72, 73},
			want:         []int{1, 1, 1, 0},
		},
		{
			name:         "All same",
			temperatures: []int{60, 60, 60},
			want:         []int{0, 0, 0},
		},
		{
			name:         "Single element",
			temperatures: []int{80},
			want:         []int{0},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := dailyTemperatures(tt.temperatures)
			if !equal(got, tt.want) {
				t.Errorf("dailyTemperatures() = %v, want %v", got, tt.want)
			}
		})
	}
}
