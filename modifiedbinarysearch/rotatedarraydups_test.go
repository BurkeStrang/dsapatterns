package modifiedbinarysearch

import "testing"

func Test_searchRotatedDups(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		key  int
		want int
	}{
		{name: "Example 1", arr: []int{3,7,3,3,3}, key: 7, want: 1 },
		{name: "Example 2", arr: []int{3,3,3,7,3}, key: 7, want: 3 },
		{name: "Example 3", arr: []int{3,3,7,3,3}, key: 7, want: 2 },
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchRotatedDups(tt.arr, tt.key)
			if got != tt.want  {
				t.Errorf("searchRotatedDups() = %v, want %v", got, tt.want)
			}
		})
	}
}

