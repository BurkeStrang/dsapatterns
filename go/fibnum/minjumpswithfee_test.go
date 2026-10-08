package fibnum

import "testing"

func Test_findMinFee(t *testing.T) {
	tests := []struct {
		name string
		fee  []int
		want int
	}{
		{name: "Example 1", fee: []int{1, 2, 5, 2, 1, 2}, want: 3},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMinFee(tt.fee)
			if got != tt.want {
				t.Errorf("findMinFee() = %v, want %v", got, tt.want)
			}
		})
	}
}
