package knapsackdp

import "testing"

func Test_canPartitionMin(t *testing.T) {
	tests := []struct {
		name string
		num  []int
		want int
	}{
		{name: "Example 1", num: []int{1, 2, 3, 9}, want: 3},
		{name: "Example 2", num: []int{1, 2, 7, 1, 5}, want: 0},
		{name: "Example 3", num: []int{1, 3, 100, 4}, want: 92},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := canPartitionMin(tt.num)
			if got != tt.want {
				t.Errorf("canPartitionMin() = %v, want %v", got, tt.want)
			}
		})
	}
}
