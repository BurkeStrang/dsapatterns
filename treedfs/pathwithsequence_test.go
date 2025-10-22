package treedfs

import "testing"

func Test_findPath(t *testing.T) {
	tests := []struct {
		name     string
		root     *TreeNode
		sequence []int
		want     bool
	}{
		{
			name:     "Example 1: Path exists",
			root:     makeTree([]*int{intPtr(1), intPtr(7), intPtr(9), nil, nil, intPtr(2), intPtr(9)}),
			sequence: []int{1, 9, 9},
			want:     true,
		},
		{
			name:     "Example 2: Path does not exist",
			root:     makeTree([]*int{intPtr(1), intPtr(0), intPtr(1), intPtr(1), intPtr(6), nil, intPtr(5)}),
			sequence: []int{1, 0, 7},
			want:     false,
		},
		{
			name:     "Example 3: Empty sequence",
			root:     makeTree([]*int{intPtr(1), intPtr(2)}),
			sequence: []int{},
			want:     false,
		},
		{
			name:     "Example 4: Empty tree",
			root:     nil,
			sequence: []int{1},
			want:     false,
		},
		{
			name:     "Example 5: Single node match",
			root:     makeTree([]*int{intPtr(5)}),
			sequence: []int{5},
			want:     true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findPath(tt.root, tt.sequence)
			if got != tt.want {
				t.Errorf("findPath() = %v, want %v", got, tt.want)
			}
		})
	}
}
