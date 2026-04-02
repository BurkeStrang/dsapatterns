package fibnum

import "testing"

func Test_factors(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "Example 1", n: 4, want: 4},
		{name: "Example 2", n: 5, want: 6},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := factors(tt.n)
			if got != tt.want {
				t.Errorf("factors() = %v, want %v", got, tt.want)
			}
		})
	}
}
