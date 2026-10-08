package palindromicsubsequence

import "testing"

func Test_findLPStringLength(t *testing.T) {
	tests := []struct {
		name string
		st   string
		want int
	}{
		{name: "Example 1", st: "abdbca", want: 3},
		{name: "Example 2", st: "cddpd", want: 3},
		{name: "Example 3", st: "pqr", want: 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findLPStringLength(tt.st)
			if got != tt.want {
				t.Errorf("findLPStringLength() = %v, want %v", got, tt.want)
			}
		})
	}
}
