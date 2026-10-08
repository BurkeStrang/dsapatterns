package greedy

import "testing"

func Test_minMoves(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want int
	}{
		{name: "Example 1", nums: []int{3, 2, 5, 1, 4}, want: 3},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := minMoves(tt.nums)
			if got != tt.want {
				t.Errorf("minMoves() = %v, want %v", got, tt.want)
			}
		})
	}
}
