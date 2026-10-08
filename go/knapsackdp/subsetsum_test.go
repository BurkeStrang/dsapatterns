package knapsackdp

import "testing"

func Test_canPartitionSum(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		sum  int
		want bool
	}{
		{name: "Example 1", nums: []int{1, 2, 3, 7}, sum: 6, want: true},
		{name: "Example 2", nums: []int{1, 2, 7, 1, 5}, sum: 10, want: true},
		{name: "Example 3", nums: []int{1, 3, 4, 8}, sum: 6, want: false},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := canPartitionSum(tt.nums, tt.sum)
			if got != tt.want {
				t.Errorf("canPartitionSum() = %v, want %v", got, tt.want)
			}
		})
	}
}
