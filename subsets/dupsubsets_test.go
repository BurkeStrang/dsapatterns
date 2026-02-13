package subsets

import "testing"

func Test_finddupSubsets(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want [][]int
	}{
		{
			name: "example test case 1",
			nums: []int{1, 3, 3},
			want: [][]int{{}, {1}, {3}, {1, 3}, {3, 3}, {1, 3, 3}},
		},
		{
			name: "example test case 2",
			nums: []int{1, 2, 3},
			want: [][]int{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := finddupSubsets(tt.nums)
			if !equalSubsets(got, tt.want) {
				t.Errorf("finddupSubsets() = %v, want %v", got, tt.want)
			}
		})
	}
}
