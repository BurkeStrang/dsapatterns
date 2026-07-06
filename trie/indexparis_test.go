package trie

import (
	"testing"
)

func TestSolutionIndex_IndexPairs(t *testing.T) {
	tests := []struct {
		name  string
		text  string
		words []string
		want  [][]int
	}{
		{name: "Test Case 1", text: "thestarsareout", words: []string{"star", "stars", "are"}, want: [][]int{{3, 6}, {3, 7}, {8, 10}}},
		{name: "Test Case 2", text: "bluebirdskyscraper", words: []string{"blue", "bird", "sky"}, want: [][]int{{0, 3}, {4, 7}, {8, 10}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var s SolutionIndex
			got := s.IndexPairs(tt.text, tt.words)
			if !equalSlices(got, tt.want) {
				t.Errorf("IndexPairs() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalSlices(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if len(a[i]) != len(b[i]) {
			return false
		}
		for j := range a[i] {
			if a[i][j] != b[i][j] {
				return false
			}
		}
	}
	return true
}
