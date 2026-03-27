package knapsackdp

import "testing"

func Test_canPartition(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want bool
	}{
		{name: "Example 1", nums: []int{1, 2, 3, 4}, want: true},
		{name: "Example 2", nums: []int{1, 1, 3, 4, 7}, want: true},
		{name: "Example 3", nums: []int{2, 3, 4, 6}, want: false},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := canPartition(tt.nums)
			if got != tt.want {
				t.Errorf("canPartition() = %v, want %v", got, tt.want)
			}
		})
	}
}
