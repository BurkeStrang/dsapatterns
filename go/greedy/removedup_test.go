package greedy

import "testing"

func Test_removeDuplicateLetters(t *testing.T) {
	tests := []struct {
		name string
		s    string
		want string
	}{
		{name: "Example 1", s: "babac", want: "abc"},
		{name: "Example 2", s: "zabccde", want: "zabcde"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := removeDuplicateLetters(tt.s)
			if got != tt.want {
				t.Errorf("removeDuplicateLetters() = %v, want %v", got, tt.want)
			}
		})
	}
}
