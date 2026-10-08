package fibnum

import "testing"

func Test_findMaxSteal(t *testing.T) {
	tests := []struct {
		name   string
		wealth []int
		want   int
	}{
		{name: "Example 1", wealth: []int{2, 5, 1, 3, 6, 2, 4}, want: 15},
		{name: "Example 1", wealth: []int{2, 10, 14, 8, 1}, want: 18},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMaxSteal(tt.wealth)
			if got != tt.want {
				t.Errorf("findMaxSteal() = %v, want %v", got, tt.want)
			}
		})
	}
}
