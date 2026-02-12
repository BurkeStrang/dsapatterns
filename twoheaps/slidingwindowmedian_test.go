package twoheaps

import (
	"testing"
)

func TestSlidingWindowMedian(t *testing.T) {
	tests := []struct {
		name     string
		nums     []int
		k        int
		expected []float64
	}{
		{
			name:     "k=2",
			nums:     []int{1, 2, -1, 3, 5},
			k:        2,
			expected: []float64{1.5, 0.5, 1.0, 4.0},
		},
		{
			name:     "k=3",
			nums:     []int{1, 2, -1, 3, 5},
			k:        3,
			expected: []float64{1.0, 2.0, 3.0},
		},
		{
			name:     "single element window",
			nums:     []int{4, 1, 3},
			k:        1,
			expected: []float64{4.0, 1.0, 3.0},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := &Solution{}
			result := s.findSlidingWindowMedian(tt.nums, tt.k)
			if len(result) != len(tt.expected) {
				t.Fatalf("expected %d results, got %d", len(tt.expected), len(result))
			}
			for i := range result {
				if result[i] != tt.expected[i] {
					t.Errorf("result[%d] = %f, expected %f", i, result[i], tt.expected[i])
				}
			}
		})
	}
}
