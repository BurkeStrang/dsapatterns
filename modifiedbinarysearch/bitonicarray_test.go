package modifiedbinarysearch

import "testing"

func Test_searchBitonic(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		key  int
		want int
	}{
		{name: "Example 1", arr: []int{1,3,8,4,3}, key: 4, want: 3 },
		{name: "Example 2", arr: []int{3,8,3,1}, key: 8, want: 1 },
		{name: "Example 3", arr: []int{1,3,8,12}, key: 12, want: 3 },
		{name: "Example 4", arr: []int{10,9,8}, key: 10, want: 0 },
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchBitonic(tt.arr, tt.key)
			if got != tt.want  {
				t.Errorf("searchBitonic() = %v, want %v", got, tt.want)
			}
		})
	}
}

