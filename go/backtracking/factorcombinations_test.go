package backtracking

import (
	"reflect"
	"sort"
	"testing"
)

func Test_getFactors(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want [][]int
	}{
		{name: "Example 1", n: 8, want: [][]int{{2, 2, 2}, {2, 4}}},
		{name: "Example 2", n: 20, want: [][]int{{2, 2, 5}, {2, 10}, {4, 5}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := getFactors(tt.n)
			if !equalSubsets(got, tt.want) {
				t.Errorf("getFactors() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalSubsets(a, b [][]int) bool {
	sortSlice := func(s [][]int) {
		for i := range s {
			sort.Ints(s[i])
		}
		sort.Slice(s, func(i, j int) bool {
			for k := range s[i] {
				if k >= len(s[j]) || s[i][k] != s[j][k] {
					return k < len(s[j]) && s[i][k] < s[j][k]
				}
			}
			return len(s[i]) < len(s[j])
		})
	}
	sortSlice(a)
	sortSlice(b)
	return reflect.DeepEqual(a, b)
}
