package subsets

import "testing"
import "reflect"
import "sort"

func Test_findSubsets(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want [][]int
	}{
		{
			name: "example test case 1",
			nums: []int{1, 3},
			want: [][]int{{}, {1}, {3}, {1, 3}},
		},
		{
			name: "example test case 2",
			nums: []int{1,2,3},
			want: [][]int{{}, {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSubsets(tt.nums)
			if !equalSubsets(got,tt.want){
				t.Errorf("findSubsets() = %v, want %v", got, tt.want)
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
