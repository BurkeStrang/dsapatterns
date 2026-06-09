package backtracking

import (
	"testing"
)

func Test_combinationSum(t *testing.T) {
	tests := []struct {
		name       string
		candidates []int
		target     int
		want       [][]int
	}{
		{name: "test1", candidates: []int{2, 3, 6, 7}, target: 7, want: [][]int{{2, 2, 3}, {7}}},
		{name: "test2", candidates: []int{2, 4, 6, 8}, target: 10, want: [][]int{{2, 2, 2, 2, 2}, {2, 2, 2, 4}, {2, 2, 6}, {2, 4, 4}, {2, 8}, {4, 6}}},
		{name: "test3", candidates: []int{2}, target: 1, want: [][]int{}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := combinationSum(tt.candidates, tt.target)
			if !equal(got, tt.want) {
				t.Errorf("combinationSum() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equal(got [][]int, want [][]int) bool {
	if len(got) != len(want) {
		return false
	}

	for i := range got {
		if len(got[i]) != len(want[i]) {
			return false
		}

		for j := range got[i] {
			if got[i][j] != want[i][j] {
				return false
			}
		}
	}
	return true
}
