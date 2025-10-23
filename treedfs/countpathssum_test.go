package treedfs

import "testing"

func Test_countPaths(t *testing.T) {
	tests := []struct {
		name      string
		root      *TreeNode
		targetSum int
		want      int
	}{
		{
			name:      "Example 1: Single path",
			root:      makeTree([]*int{intPtr(1), intPtr(2), intPtr(3)}),
			targetSum: 3,
			want:      2, // Paths: [1,2], [3]
		},
		{
			name:      "Example 2: Multiple paths",
			root:      makeTree([]*int{intPtr(10), intPtr(5), intPtr(-3), intPtr(3), intPtr(2), nil, intPtr(11), intPtr(3), intPtr(-2), nil, intPtr(1)}),
			targetSum: 8,
			want:      3, // Paths: [5,3], [5,2,1], [10,-3,1]
		},
		{
			name:      "Example 3: No path",
			root:      makeTree([]*int{intPtr(1), intPtr(2)}),
			targetSum: 100,
			want:      0,
		},
		{
			name:      "Example 4: Empty tree",
			root:      nil,
			targetSum: 0,
			want:      0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countPaths(tt.root, tt.targetSum)
			if got != tt.want {
				t.Errorf("countPaths() = %v, want %v", got, tt.want)
			}
		})
	}
}
