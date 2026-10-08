package trie

import "testing"

func Test_minChar_MinExtraChar(t *testing.T) {
	tests := []struct {
		name       string
		s          string
		dictionary []string
		want       int
	}{
		{name: "Test Case 1", s: "amazingracecar", dictionary: []string{"race"}, want: 10},
		{name: "Test Case 1", s: "amazingracecar", dictionary: []string{"race", "car"}, want: 7},
		{name: "Test Case 2", s: "bookkeeperreading", dictionary: []string{"keep", "read"}, want: 9},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var sol minChar
			got := sol.MinExtraChar(tt.s, tt.dictionary)
			if got != tt.want {
				t.Errorf("MinExtraChar() = %v, want %v", got, tt.want)
			}
		})
	}
}
