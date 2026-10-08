package trie

import (
	"testing"
)

func TestSolution_Search(t *testing.T) {
	tests := []struct {
		name string
		word string
		want bool
	}{
		{name: "Search 'grape'", word: "grape", want: true},
		{name: "Search 'grapefruit'", word: "grapefruit", want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := NewSolution()
			s.Insert(tt.word)
			got := s.Search(tt.word)
			if got != tt.want {
				t.Errorf("Search() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestSolution_StartsWith(t *testing.T) {
	tests := []struct {
		name   string
		prefix string
		word   string
		want   bool
	}{
		{name: "StartsWith 'grap'", prefix: "grap", word: "grape", want: true},
		{name: "StartsWith 'gr'", prefix: "gr", word: "grape", want: true},
		{name: "StartsWith 'gra'", prefix: "gra", word: "grape", want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := NewSolution()
			s.Insert(tt.word)
			got := s.StartsWith(tt.prefix)
			if got != tt.want {
				t.Errorf("StartsWith() = %v, want %v", got, tt.want)
			}
		})
	}
}
