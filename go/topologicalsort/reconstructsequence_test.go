package topologicalsort

import "testing"

func Test_canConstruct(t *testing.T) {
	tests := []struct {
		name        string
		originalSeq []int
		sequences   [][]int
		want        bool
	}{
		{name: "Example 1", originalSeq: []int{1, 2, 3, 4}, sequences: [][]int{{1, 2}, {2, 3}, {3, 4}}, want: true},
		{name: "Example 2", originalSeq: []int{1, 2, 3, 4}, sequences: [][]int{{1, 2}, {2, 3}, {2, 4}}, want: false},
		{name: "Example 3", originalSeq: []int{3, 1, 4, 2, 5}, sequences: [][]int{{3, 1, 5}, {1, 4, 2, 5}}, want: true},
		{name: "Different order", originalSeq: []int{1, 2, 3}, sequences: [][]int{{3, 2}, {2, 1}}, want: false},
		{name: "Missing number", originalSeq: []int{1, 2, 3}, sequences: [][]int{{1, 2}}, want: false},
		{name: "Cyclic sequences", originalSeq: []int{1, 2, 3}, sequences: [][]int{{1, 2}, {2, 3}, {3, 1}}, want: false},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := canConstruct(tt.originalSeq, tt.sequences)
			if got != tt.want {
				t.Errorf("canConstruct() = %v, want %v", got, tt.want)
			}
		})
	}
}
