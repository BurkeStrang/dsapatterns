package topologicalsort

import "testing"

func Test_findAlienOrder(t *testing.T) {
	tests := []struct {
		name  string
		words []string
		want  string
	}{
		{name: "Example 1", words: []string{"ba", "bc", "ac", "cab"}, want: "bac"},
		{name: "Example 2", words: []string{"cab", "aaa", "aab"}, want: "cab"},
		{name: "Example 3", words: []string{"ywx", "wz", "xww", "xz", "zyy", "zwz"}, want: "ywxz"},
		{name: "Word before its own prefix", words: []string{"abc", "ab"}, want: ""},
		{name: "Cyclic ordering", words: []string{"a", "b", "a"}, want: ""},
		{name: "No words", words: []string{}, want: ""},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findAlienOrder(tt.words)
			if got != tt.want {
				t.Errorf("findAlienOrder() = %q, want %q", got, tt.want)
			}
		})
	}
}
