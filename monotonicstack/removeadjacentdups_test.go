package monotonicstack

import "testing"

func Test_removeDuplicates(t *testing.T) {
	tests := []struct {
		name string
		s    string
		want string
	}{
		{"empty string", "", ""},
		{"no duplicates", "abcd", "abcd"},
		{"all removed", "abccba", ""},
		{"simple pair", "aabb", ""},
		{"single removal", "foobar", "fbar"},
		{"triple duplicate", "fooobar", "fobar"},
		{"nested removals", "azxxzy", "ay"},
		{"single char", "a", "a"},
		{"all same", "aaaa", ""},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := removeDuplicates(tt.s)
			if got != tt.want {
				t.Errorf("removeDuplicates(%q) = %q, want %q", tt.s, got, tt.want)
			}
		})
	}
}
