package knapsackdp

import "testing"

func Test_solveKnapsack(t *testing.T) {
	tests := []struct {
		name     string
		profits  []int
		weights  []int
		capacity int
		want     int
	}{
		{name: "Example", weights: []int{2, 3, 1, 4}, profits: []int{4, 5, 3, 7}, capacity: 5, want: 10},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := solveKnapsack(tt.profits, tt.weights, tt.capacity)
			if got != tt.want {
				t.Errorf("solveKnapsack() = %v, want %v", got, tt.want)
			}
		})
	}
}
