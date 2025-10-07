package cyclicalsort

import "testing"

func Test_findFirstK(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		k    int
		want []int
	}{
		{
			name: "Example 1",
			nums: []int{3, -1, 4, 5, 5},
			k:    3,
			want: []int{1, 2, 6},
		},
		{
			name: "Example 2",
			nums: []int{2, 3, 4},
			k:    3,
			want: []int{1, 5, 6},
		},
		{
			name: "Example 3",
			nums: []int{-2, -3, 4},
			k:    2,
			want: []int{1, 2},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findFirstK(tt.nums, tt.k)
			if !equal(got,tt.want) {
				t.Errorf("findFirstK() = %v, want %v", got, tt.want)
			}
		})
	}
}

