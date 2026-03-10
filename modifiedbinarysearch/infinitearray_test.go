package modifiedbinarysearch

import "testing"

func Test_searchInfiniteSortedArray(t *testing.T) {
	tests := []struct {
		name string
		reader ArrayReader
		key    int
		want   int
	}{
		{name: "Example 1", reader: ArrayReader{Arr: []int{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}}, key: 16, want: 6},
		{name: "Example 2", reader: ArrayReader{Arr: []int{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}}, key: 11, want: -1},
		{name: "Example 3", reader: ArrayReader{Arr: []int{1, 3, 8, 10, 15}}, key: 15, want: 4},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchInfiniteSortedArray(tt.reader, tt.key)
			if got != tt.want {
				t.Errorf("searchInfiniteSortedArray() = %v, want %v", got, tt.want)
			}
		})
	}
}

