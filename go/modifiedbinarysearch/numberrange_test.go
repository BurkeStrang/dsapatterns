package modifiedbinarysearch

import "testing"

func Test_findRange(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		key  int
		want [2]int
	}{
		{name: "example1", arr: []int{4, 6, 6, 6, 9}, key: 6, want: [2]int{1, 3}},
		{name: "example2", arr: []int{1, 3, 8, 10, 15}, key: 10, want: [2]int{3, 3}},
		{name: "example3", arr: []int{1, 3, 8, 10, 15}, key: 12, want: [2]int{-1, -1}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findRange(tt.arr, tt.key)
			if got[0] != tt.want[0] || got[1] != tt.want[1] {
				t.Errorf("findRange() = %v, want %v", got, tt.want)
			}
		})
	}
}
