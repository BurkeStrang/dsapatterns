package greedy

import "testing"

func Test_findLongestChain(t *testing.T) {
	tests := []struct {
		name  string
		pairs [][]int
		want  int
	}{
		{name: "Example 1", pairs: [][]int{{1, 2}, {3, 4}, {2, 3}}, want: 2},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findLongestChain(tt.pairs)
			if got != tt.want {
				t.Errorf("findLongestChain() = %v, want %v", got, tt.want)
			}
		})
	}
}
