package fibnum

import (
	"math"
	"testing"
)

func Test_countMinJumps(t *testing.T) {
	tests := []struct {
		name  string
		jumps []int
		want  int
	}{
		{name: "Example 1", jumps: []int{2, 1, 1, 1, 4}, want: 3},
		{name: "Example 2", jumps: []int{1, 1, 3, 6, 9, 3, 0, 1, 3}, want: 4},
		{name: "Blocked by a zero", jumps: []int{1, 0, 2}, want: math.MaxInt32},
		{name: "Single element", jumps: []int{0}, want: 0},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countMinJumps(tt.jumps)
			if got != tt.want {
				t.Errorf("countMinJumps() = %v, want %v", got, tt.want)
			}
		})
	}
}
