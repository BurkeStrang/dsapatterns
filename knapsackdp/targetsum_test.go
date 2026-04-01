package knapsackdp

import "testing"

func Test_findTargetSubsets(t *testing.T) {
	tests := []struct {
		name string
		num  []int
		str  int
		want int
	}{
		{name: "Example 1", num: []int{1, 1, 2, 3}, str: 1, want: 3},
		{name: "Example 2", num: []int{1, 2, 7, 1}, str: 9, want: 2},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findTargetSubsets(tt.num, tt.str)
			if got != tt.want {
				t.Errorf("findTargetSubsets() = %v, want %v", got, tt.want)
			}
		})
	}
}
