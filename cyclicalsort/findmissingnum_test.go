package cyclicalsort

import "testing"

func Test_findMissingNumber(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want int
	}{
		{
			name: "Example 1",
			nums: []int{4, 0, 3, 1},
			want: 2,
		},
		{
			name: "Example 2",
			nums: []int{8, 3, 5, 2, 4, 6, 0, 1},
			want: 7,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMissingNumber(tt.nums)
			if got != tt.want {
				t.Errorf("findMissingNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
