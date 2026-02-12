package twoheaps

import "testing"

func TestFindMaximumCapital(t *testing.T) {
	tests := []struct {
		name             string
		capital          []int
		profits          []int
		numberOfProjects int
		initialCapital   int
		expected         int
	}{
		{
			name:             "basic example",
			capital:          []int{0, 1, 2},
			profits:          []int{1, 2, 3},
			numberOfProjects: 2,
			initialCapital:   1,
			expected:         6,
		},
		{
			name:             "not enough capital for any project",
			capital:          []int{5, 10, 15},
			profits:          []int{1, 2, 3},
			numberOfProjects: 3,
			initialCapital:   0,
			expected:         0,
		},
		{
			name:             "all projects affordable from start",
			capital:          []int{0, 0, 0},
			profits:          []int{1, 2, 3},
			numberOfProjects: 2,
			initialCapital:   0,
			expected:         5,
		},
		{
			name:             "single project",
			capital:          []int{0},
			profits:          []int{5},
			numberOfProjects: 1,
			initialCapital:   0,
			expected:         5,
		},
		{
			name:             "chain of unlocking projects",
			capital:          []int{0, 1, 2, 3},
			profits:          []int{1, 1, 1, 1},
			numberOfProjects: 4,
			initialCapital:   0,
			expected:         4,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			result := findMaximumCapital(tt.capital, tt.profits, tt.numberOfProjects, tt.initialCapital)
			if result != tt.expected {
				t.Errorf("got %d, expected %d", result, tt.expected)
			}
		})
	}
}
