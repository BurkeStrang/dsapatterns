package topkelements

import "testing"

func Test_findClosestElements(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		K    int
		X    int
		want []int
	}{
		{name: "Example 1", arr: []int{5, 6, 7, 8, 9}, K: 3, X: 7, want: []int{6, 7, 8}},
		{name: "Example 2", arr: []int{2, 4, 5, 6, 9}, K: 3, X: 6, want: []int{4, 5, 6}},
		{name: "Example 3", arr: []int{2, 4, 5, 6, 9}, K: 3, X: 10, want: []int{5, 6, 9}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findClosestElements(tt.arr, tt.K, tt.X)
			if got == nil || len(got) != len(tt.want) {
				if got[0] != tt.want[0] && got[1] != tt.want[1] && got[2] != tt.want[2] {
					t.Errorf("findClosestElements() = %v, want %v", got, tt.want)
				}
			}
		})
	}
}
