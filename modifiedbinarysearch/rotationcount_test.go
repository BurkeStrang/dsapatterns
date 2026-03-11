package modifiedbinarysearch

import "testing"

func Test_countRotations(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want int
	}{
		{name: "Example 1", arr: []int{10, 15, 1, 3, 8}, want: 2},
		{name: "Example 2", arr: []int{4, 5, 7, 9, 10, -1, 2}, want: 5},
		{name: "Example 3", arr: []int{1, 3, 8, 10}, want: 0},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countRotations(tt.arr)
			if tt.want != got {
				t.Errorf("countRotations() = %v, want %v", got, tt.want)
			}
		})
	}
}
