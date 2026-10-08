package palindromicsubsequence

import "testing"

func Test_findMinimumDeletions(t *testing.T) {
	tests := []struct {
		name string
		st   string
		want int
	}{
		{name: "Example 1", st: "abdbca", want: 1},
		{name: "Example 2", st: "cddpd", want: 2},
		{name: "Example 3", st: "pqr", want: 2},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMinimumDeletions(tt.st)
			if got != tt.want {
				t.Errorf("findMinimumDeletions() = %v, want %v", got, tt.want)
			}
		})
	}
}
