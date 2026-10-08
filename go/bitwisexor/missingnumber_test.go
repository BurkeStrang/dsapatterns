package bitwisexor

import "testing"

func Test_findMissingNumber(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want int
	}{
		{name: "Example 1", arr: []int{1, 2, 3, 5}, want: 4},
		{name: "Example 2", arr: []int{1, 2, 4, 5}, want: 3},
		{name: "Example 3", arr: []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, want: 21},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMissingNumber(tt.arr)
			if got != tt.want {
				t.Errorf("findMissingNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
