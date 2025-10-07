package cyclicalsort

import "testing"

func Test_findCorrupt(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want []int
	}{
		{
			name: "Example 1",
			nums: []int{3, 1, 2, 5, 2},
			want: []int{2, 4},
		},
		{
			name: "Example 2",
			nums: []int{3, 1, 2, 3, 6, 4},
			want: []int{3, 5},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findCorrupt(tt.nums)
			if !equal(got,tt.want) {
				t.Errorf("findCorrupt() = %v, want %v", got, tt.want)
			}
		})
	}
}

