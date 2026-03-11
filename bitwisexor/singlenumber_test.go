package bitwisexor

import "testing"

func Test_findSingleNumber(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want int
	}{
		{name: "Example 1", arr: []int{1, 4, 2, 1, 3, 2, 3}, want: 4},
		{name: "Example 2", arr: []int{7, 9, 7}, want: 9},
		{name: "Example 3", arr: []int{5, 6, 7, 5, 6}, want: 7},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSingleNumber(tt.arr)
			if got != tt.want {
				t.Errorf("findSingleNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
