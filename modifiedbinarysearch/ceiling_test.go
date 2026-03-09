package modifiedbinarysearch

import "testing"

func Test_searchCeilingOfANumber(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		arr  []int
		key  int
		want int
	}{
		{name: "key exists in array", arr: []int{1, 3, 8, 10, 15}, key: 8, want: 2},
		{name: "key between two elements", arr: []int{1, 3, 8, 10, 15}, key: 12, want: 4},
		{name: "key smaller than all elements", arr: []int{1, 3, 8, 10, 15}, key: 0, want: 0},
		{name: "key larger than all elements", arr: []int{1, 3, 8, 10, 15}, key: 20, want: -1},
		{name: "key is smallest element", arr: []int{1, 3, 8, 10, 15}, key: 1, want: 0},
		{name: "key is largest element", arr: []int{1, 3, 8, 10, 15}, key: 15, want: 4},
		{name: "key just below a middle element", arr: []int{2, 4, 6, 8, 10}, key: 5, want: 2},
		{name: "single element - key matches", arr: []int{5}, key: 5, want: 0},
		{name: "single element - key is smaller", arr: []int{5}, key: 3, want: 0},
		{name: "single element - key is larger", arr: []int{5}, key: 7, want: -1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchCeilingOfANumber(tt.arr, tt.key)
			if got != tt.want {
				t.Errorf("searchCeilingOfANumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
