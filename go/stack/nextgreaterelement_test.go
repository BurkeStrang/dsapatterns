package stack

import "testing"

func Test_nextLargerElement(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want []int
	}{
		{"Example 1", []int{4, 5, 2, 25}, []int{5, 25, 25, -1}},
		{"Example 2", []int{13, 7, 6, 12}, []int{-1, 12, 12, -1}},
		{"Example 3", []int{1, 2, 3, 4, 5}, []int{2, 3, 4, 5, -1}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := nextLargerElement(tt.arr)
			for i := range got {
				if got[i] != tt.want[i] {
					t.Errorf("nextLargerElement() = %v, want %v", got, tt.want)
					break
				}
			}
		})
	}
}
