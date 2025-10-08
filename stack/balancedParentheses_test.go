package stack

import "testing"

func Test_validParentheses(t *testing.T) {
	tests := []struct {
		name string
		s1   string
		want bool
	}{
		{
			name: "Example 1 - balanced",
			s1:   "{[()]}",
			want: true,
		},
		{
			name: "Example 2 - not balanced",
			s1:   "{[}]",
			want: false,
		},
		{
			name: "Example 3 - not balanced",
			s1:   "(]",
			want: false,
		},
		{
			name: "Empty string - balanced",
			s1:   "",
			want: true,
		},
		{
			name: "Single type - balanced",
			s1:   "()[]{}",
			want: true,
		},
		{
			name: "Single type - not balanced",
			s1:   "(((",
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := validParentheses(tt.s1)
			if got != tt.want {
				t.Errorf("validParentheses() = %v, want %v", got, tt.want)
			}
		})
	}
}
