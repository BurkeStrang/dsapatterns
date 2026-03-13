package topkelements

import (
	"testing"
)

func Test_findTopKFrequentNumbers(t *testing.T) {
	tests := []struct {
		name  string
		nums  []int
		k     int
		valid map[int]bool
	}{
		{
			name:  "Example 1",
			nums:  []int{1, 3, 5, 12, 11, 12, 11},
			k:     2,
			valid: map[int]bool{11: true, 12: true},
		},
		{
			name:  "Example 2",
			nums:  []int{5, 12, 11, 3, 11},
			k:     2,
			valid: map[int]bool{11: true, 5: true, 12: true, 3: true},
		},
		{
			name:  "Example 3",
			nums:  []int{1, 1, 1, 3, 3, 3, 5, 5, 5, 12},
			k:     2,
			valid: map[int]bool{1: true, 3: true, 5: true},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findTopKFrequentNumbers(tt.nums, tt.k)

			if len(got) != tt.k {
				t.Fatalf("expected %d elements, got %d: %v", tt.k, len(got), got)
			}

			for _, v := range got {
				if !tt.valid[v] {
					t.Errorf("unexpected value %d in result %v", v, got)
				}
			}
		})
	}
}
