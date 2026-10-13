package unionfind

import (
	"reflect"
	"testing"
)

func Test_findRedundantConnection(t *testing.T) {
	tests := []struct {
		name  string
		edges [][]int
		want  []int
	}{
		{name: "Example 1", edges: [][]int{{1, 2}, {1, 3}, {3, 4}, {1, 4}, {1, 5}}, want: []int{1, 4}},
		{name: "Example 2", edges: [][]int{{1, 2}, {2, 3}, {3, 1}, {3, 4}}, want: []int{3, 1}},
		{name: "Example 3", edges: [][]int{{1, 2}, {2, 3}, {3, 4}, {4, 2}, {5, 6}}, want: []int{4, 2}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findRedundantConnection(tt.edges)
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("findRedundantConnection() = %v, want %v", got, tt.want)
			}
		})
	}
}
