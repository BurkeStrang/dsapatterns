package greedy

import "testing"

func Test_largestPalindromic(t *testing.T) {
	tests := []struct {
		name string
		s    string
		want string
	}{
		{name: "Example 1", s: "323211444", want: "432141234"},
		{name: "Example 3", s: "54321", want: "5"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := largestPalindromic(tt.s)
			if got != tt.want {
				t.Errorf("largestPalindromic() = %v, want %v", got, tt.want)
			}
		})
	}
}
