package backtracking

import "testing"

func Test_maxUniqueSplit(t *testing.T) {
	tests := []struct {
		name string
		str  string
		want int
	}{
		{name: "Example 1", str: "ababccc", want: 5},
		{name: "Example 2", str: "aba", want: 2},
		{name: "Example 3", str: "aa", want: 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxUniqueSplit(tt.str)
			if got != tt.want {
				t.Errorf("maxUniqueSplit() = %v, want %v", got, tt.want)
			}
		})
	}
}
