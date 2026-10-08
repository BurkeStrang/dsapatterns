package cyclicalsort

import "testing"

func Test_findDup(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		nums []int
		want int
	}{
		{
			name: "Example 1",
			nums: []int{1, 4, 4, 3, 2},
			want: 4,
		},
		{
			name: "Example 2",
			nums: []int{2, 1, 3, 3, 5, 4},
			want: 3,
		},
		{
			name: "Example 3",
			nums: []int{2, 4, 1, 4, 4},
			want: 4,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findDup(tt.nums)
			if got != tt.want {
				t.Errorf("findDup() = %v, want %v", got, tt.want)
			}
		})
	}
}
