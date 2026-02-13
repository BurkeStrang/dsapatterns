package subsets

import "testing"

func Test_findPermutations(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want [][]int
	}{
		{
			name: "3 elements",
			nums: []int{1, 2, 3},
			want: [][]int{
				{1, 2, 3},
				{1, 3, 2},
				{2, 1, 3},
				{2, 3, 1},
				{3, 1, 2},
				{3, 2, 1},
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findPermutations(tt.nums)
			if !equalSubsets(got, tt.want) {
				t.Errorf("findPermutations() = %v, want %v", got, tt.want)
			}
		})
	}
}

