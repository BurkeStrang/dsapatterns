package topkelements

import "testing"

func Test_minimumCostToConnectRopes(t *testing.T) {
	tests := []struct {
		name        string
		ropeLengths []int
		want        int
	}{
		{name: "Example 1", ropeLengths: []int{1, 2, 3, 4, 5}, want: 33},
		{name: "Example 2", ropeLengths: []int{3, 4, 5, 6}, want: 36},
		{name: "Example 3", ropeLengths: []int{1, 3, 11, 5, 2}, want: 42},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := minimumCostToConnectRopes(tt.ropeLengths)
			if got != tt.want {
				t.Errorf("minimumCostToConnectRopes() = %v, want %v", got, tt.want)
			}
		})
	}
}
