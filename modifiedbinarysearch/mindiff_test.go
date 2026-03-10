package modifiedbinarysearch

import "testing"

func Test_searchMinDiff(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		key  int
		want int
	}{
		{name: "Example 1", arr: []int{4, 6, 10}, key: 7, want: 6},
		{name: "Example 2", arr: []int{4, 6, 10}, key: 4, want: 4},
		{name: "Example 3", arr: []int{1, 3, 8, 10, 15}, key: 12, want: 10},
		{name: "Example 4", arr: []int{4, 6, 10}, key: 17, want: 10},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchMinDiff(tt.arr, tt.key)
			if got != tt.want {
				t.Errorf("searchMinDiff() = %v, want %v", got, tt.want)
			}
		})
	}
}

