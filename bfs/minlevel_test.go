package bfs

import "testing"

func Test_findDepth(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		root *TreeNode
		want int
	}{
		{
			name: "Example 1",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val: 2,
					Left: &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{Val: 3},
			},
			want: 2,
		},
		{
			name: "Example 2",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{Val: 2},
			},
			want: 2,
		},
		{
			name: "Example 3",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val: 2,
					Left: &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{
					Val: 3,
					Left: &TreeNode{Val: 6},
				},
			},
			want: 3,
		},
		{
			name: "Example 4",
			root: &TreeNode{Val: 1},
			want: 1,
		},
		{
			name: "Empty tree",
			root: nil,
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findDepth(tt.root)
			if got != tt.want {
				t.Errorf("findDepth() = %v, want %v", got, tt.want)
			}
		})
	}
}

