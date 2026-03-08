package modifiedbinarysearch

import "testing"

func Test_descorascsearch(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		arr  []int
		key  int
		want int
	}{
		{name: "ascending - key found in middle", arr: []int{1, 3, 5, 7, 9}, key: 5, want: 2},
		{name: "ascending - key found at start", arr: []int{1, 3, 5, 7, 9}, key: 1, want: 0},
		{name: "ascending - key found at end", arr: []int{1, 3, 5, 7, 9}, key: 9, want: 4},
		{name: "ascending - key not found", arr: []int{1, 3, 5, 7, 9}, key: 4, want: -1},
		{name: "descending - key found in middle", arr: []int{9, 7, 5, 3, 1}, key: 5, want: 2},
		{name: "descending - key found at start", arr: []int{9, 7, 5, 3, 1}, key: 9, want: 0},
		{name: "descending - key found at end", arr: []int{9, 7, 5, 3, 1}, key: 1, want: 4},
		{name: "descending - key not found", arr: []int{9, 7, 5, 3, 1}, key: 4, want: -1},
		{name: "single element - found", arr: []int{42}, key: 42, want: 0},
		{name: "single element - not found", arr: []int{42}, key: 7, want: -1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := descorascsearch(tt.arr, tt.key)
			if got != tt.want {
				t.Errorf("descorascsearch() = %v, want %v", got, tt.want)
			}
		})
	}
}
