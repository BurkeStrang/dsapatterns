package levelordertraversal

import (
	"testing"
)

func TestTraverse(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		root *TreeNode
		want [][]int
	}{
		{
			name: "Example 1",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val:   2,
					Left:  &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{
					Val:   3,
					Left:  &TreeNode{Val: 6},
					Right: &TreeNode{Val: 7},
				},
			},
			want: [][]int{{4, 5, 6, 7}, {2, 3}, {1}},
		},
		{
			name: "Example 2",
			root: &TreeNode{
				Val: 12,
				Left: &TreeNode{
					Val:   7,
					Right: &TreeNode{Val: 9},
				},
				Right: &TreeNode{
					Val:   1,
					Left:  &TreeNode{Val: 10},
					Right: &TreeNode{Val: 5},
				},
			},
			want: [][]int{{9, 10, 5}, {7, 1}, {12}},
		},
		{
			name: "Example 3",
			root: &TreeNode{
				Val: 6,
				Left: &TreeNode{
					Val: 5,
				},
				Right: &TreeNode{
					Val: 2,
					Left: &TreeNode{
						Val:   1,
						Left:  &TreeNode{Val: 3},
						Right: &TreeNode{Val: 56},
					},
					Right: &TreeNode{
						Val:   6,
						Right: &TreeNode{Val: 3},
					},
				},
			},
			want: [][]int{{3, 56, 3}, {1, 6}, {5, 2}, {6}},
		},
		{
			name: "Empty tree",
			root: nil,
			want: [][]int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := Traverse(tt.root)
			if !equal(got, tt.want) {
				t.Errorf("Traverse() = %v, want %v", got, tt.want)
			}
		})
	}
}
