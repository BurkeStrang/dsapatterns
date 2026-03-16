package topkelements

import "testing"

func TestKthLargest_add(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		k    int
		num  int
		want int
	}{
		{name: "Example 1", nums: []int{3, 1, 5, 12, 2, 11}, k: 4, num: 6, want: 5},
		{name: "Example 2", nums: []int{3, 1, 5, 12, 2, 11}, k: 4, num: 13, want: 5},
		{name: "Example 3", nums: []int{3, 1, 5, 12, 2, 11}, k: 4, num: 4, want: 4},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := Constructor(tt.nums, tt.k)
			got := s.add(tt.num)
			if got != tt.want {
				t.Errorf("add() = %v, want %v", got, tt.want)
			}
		})
	}
}
