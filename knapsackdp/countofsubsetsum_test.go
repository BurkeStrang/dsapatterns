package knapsackdp

import "testing"

func Test_countSubsets(t *testing.T) {
	tests := []struct {
		name string
		num  []int
		sum  int
		want int
	}{
		{name: "Example 1", num: []int{1, 1, 2, 3}, sum: 4, want: 3},
		{name: "Example 2", num: []int{1, 2, 7, 1, 5}, sum: 9, want: 3},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countSubsets(tt.num, tt.sum)
			if got != tt.want {
				t.Errorf("countSubsets() = %v, want %v", got, tt.want)
			}
		})
	}
}
