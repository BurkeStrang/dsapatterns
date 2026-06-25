package trie_test

import (
	"testing"

	"dsapatterns/trie"
)

func TestSolution_SearchNode(t *testing.T) {
	tests := []struct {
		name string
		add  []string
		word string
		want bool
	}{
		{name: "SearchNode 'c.t'", add: []string{"cat", "dog"}, word: "c.t", want: true},
		{name: "SearchNode 'd..g'", add: []string{"cat", "dog"}, word: "d..g", want: false},
		{name: "SearchNode 'h.llo'", add: []string{"hello"}, word: "h.llo", want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := trie.NewSolution()
			for _, w := range tt.add {
				s.AddWord(w)
			}
			got := s.SearchNode(tt.word)
			if got != tt.want {
				t.Errorf("SearchNode() = %v, want %v", got, tt.want)
			}
		})
	}
}
