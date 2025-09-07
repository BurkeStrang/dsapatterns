package fastandslowpointers

import "testing"

func TestLoopExists(t *testing.T) {
	tests := []struct {
		arr      []int
		expected bool
	}{
		{[]int{1, 2, -1, 2, 2}, true},    // Example 1
		{[]int{2, 2, -1, 2}, true},       // Example 2
		{[]int{2, 1, -1, -2}, false},     // Example 3
		{[]int{1, -1, 1, -1}, false},     // No cycle, alternating directions
		{[]int{3, 1, 2}, true},           // Simple cycle
	}

	for _, tt := range tests {
		result := loopExists(tt.arr)
		if result != tt.expected {
			t.Errorf("loopExists(%v) = %v; want %v", tt.arr, result, tt.expected)
		}
	}
}
