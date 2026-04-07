package palindromicsubsequence

import "testing"

func Test_findCPS(t *testing.T) {
	tests := []struct {
		name string
		st   string
		want int
	}{
		{name: "Example1", st: "abdbca", want: 7},
		// {name: "Example2", st: "cddpd", want: 7},
		// {name: "Example3", st: "pqr", want: 3},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findCPS(tt.st)
			if got != tt.want {
				t.Errorf("findCPS() = %v, want %v", got, tt.want)
			}
		})
	}
}
