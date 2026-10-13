package orderedset

import (
	"reflect"
	"testing"
)

func Test_mergeSimilarItems(t *testing.T) {
	tests := []struct {
		name   string
		items1 [][]int
		items2 [][]int
		want   [][]int
	}{
		{name: "Example 1", items1: [][]int{{1, 2}, {4, 3}}, items2: [][]int{{2, 1}, {4, 3}, {3, 4}}, want: [][]int{{1, 2}, {2, 1}, {3, 4}, {4, 6}}},
		{name: "Example 2", items1: [][]int{{5, 5}}, items2: [][]int{{5, 10}}, want: [][]int{{5, 15}}},
		{name: "Example 3", items1: [][]int{{1, 1}, {2, 2}}, items2: [][]int{{3, 3}}, want: [][]int{{1, 1}, {2, 2}, {3, 3}}},
		{name: "Unsorted input", items1: [][]int{{9, 1}, {2, 2}}, items2: [][]int{{5, 3}, {2, 4}}, want: [][]int{{2, 6}, {5, 3}, {9, 1}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := mergeSimilarItems(tt.items1, tt.items2)
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("mergeSimilarItems() = %v, want %v", got, tt.want)
			}
		})
	}
}
