package modifiedbinarysearch

import "testing"

func Test_searchRotated(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		key  int
		want int
	}{
		{name: "Example 1", arr: []int{10,15,1,3,8}, key: 15, want: 1 },
		{name: "Example 2", arr: []int{4,5,7,9,10,-1,2}, key: 10, want: 4 },
		{name: "Example 3", arr: []int{10,15,1,3,8}, key: 100, want: -1 },
		{name: "Example 4", arr: []int{10,15,1,3,8}, key: 1, want: 2 },
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchRotated(tt.arr, tt.key)
			if got != tt.want  {
				t.Errorf("searchRotated() = %v, want %v", got, tt.want)
			}
		})
	}
}

