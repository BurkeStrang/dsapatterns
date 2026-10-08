package fibnum

import "testing"

func Test_countWays(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "Example 1", n: 3, want: 4},
		{name: "Example 2", n: 4, want: 7},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countWays(tt.n)
			if got != tt.want {
				t.Errorf("countWays() = %v, want %v", got, tt.want)
			}
		})
	}
}
