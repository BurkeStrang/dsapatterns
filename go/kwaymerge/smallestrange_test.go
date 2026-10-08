package kwaymerge

import "testing"

func Test_findSmallestRange(t *testing.T) {
	tests := []struct {
		name       string
		inputLists [][]int
		want       [2]int
	}{
		{name: "Example 1", inputLists: [][]int{{1, 5, 8}, {4, 12}, {7, 8, 10}}, want: [2]int{4, 7}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSmallestRange(tt.inputLists)
			if got[0] != tt.want[0] && got[1] != tt.want[1] {
				t.Errorf("findSmallestRange() = %v, want %v", got, tt.want)
			}
		})
	}
}
