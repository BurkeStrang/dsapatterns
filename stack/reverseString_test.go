package stack

import "testing"

func Test_reverseString(t *testing.T) {
	tests := []struct {
		name string
		input string
		want  string
	}{
		{"Example 1", "Hello, World!", "!dlroW ,olleH"},
		{"Example 2", "OpenAI", "IAnepO"},
		{"Example 3", "Stacks are fun!", "!nuf era skcatS"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := reverseString(tt.input)
			if got != tt.want {
				t.Errorf("reverseString() = %v, want %v", got, tt.want)
			}
		})
	}
}

