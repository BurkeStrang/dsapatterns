package fibnum

import "testing"

func Test_calculateFibonacci(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "Example 1", n: 0, want: 0},
		{name: "Example 2", n: 1, want: 1},
		{name: "Example 3", n: 2, want: 1},
		{name: "Example 4", n: 3, want: 2},
		{name: "Example 5", n: 4, want: 3},
		{name: "Example 6", n: 55, want: 139583862445},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := calculateFibonacci(tt.n)
			if got != tt.want {
				t.Errorf("calculateFibonacci() = %v, want %v", got, tt.want)
			}
		})
	}
}
