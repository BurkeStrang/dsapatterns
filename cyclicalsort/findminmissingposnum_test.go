package cyclicalsort

import "testing"

func Test_findMis(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want int
	}{
		{
			name: "Example 1",
			nums: []int{-3, 1, 5, 4, 2},
			want: 3,
		},
		{
			name: "Example 2",
			nums: []int{3, -2, 0, 1, 2},
			want: 4,
		},
		{
			name: "Example 3",
			nums: []int{3, 2, 5, 1},
			want: 4,
		},
		{
			name: "Example 4",
			nums: []int{33, 37, 5},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMis(tt.nums)
			if got != tt.want {
				t.Errorf("findMis() = %v, want %v", got, tt.want)
			}
		})
	}
}

