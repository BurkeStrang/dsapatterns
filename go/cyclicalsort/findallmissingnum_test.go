package cyclicalsort

import "testing"

func Test_findNumbers(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want []int
	}{
		{
			name: "Example 1",
			nums: []int{2, 3, 1, 8, 2, 3, 5, 1},
			want: []int{4, 6, 7},
		},
		{
			name: "Example 2",
			nums: []int{2, 4, 1, 2},
			want: []int{3},
		},
		{
			name: "Example 3",
			nums: []int{2, 3, 2, 1},
			want: []int{4},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findNumbers(tt.nums)
			if !equal(got, tt.want) {
				t.Errorf("findNumbers() = %v, want %v", got, tt.want)
			}
		})
	}
}
