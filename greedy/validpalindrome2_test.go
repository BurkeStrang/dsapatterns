package greedy

import "testing"

func Test_isPalindromePossible(t *testing.T) {
	tests := []struct {
		name  string
		input string
		want  bool
	}{
		{name: "Example 1", input: "racecar", want: true},
		{name: "Example 2", input: "abeccdeba", want: true},
		{name: "Example 3", input: "abcdef", want: false},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isPalindromePossible(tt.input)
			if got != tt.want {
				t.Errorf("isPalindromePossible() = %v, want %v", got, tt.want)
			}
		})
	}
}
