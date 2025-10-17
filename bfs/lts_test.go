package bfs

import "testing"

func Test_traversebasic(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		root *TreeNode
		want [][]int
	}{
		{
			name: "Example 1: [1,2,3,4,5,null,6]",
			root: &TreeNode{Val: 1,
				Left: &TreeNode{Val: 2,
					Left:  &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{Val: 3,
					Right: &TreeNode{Val: 6},
				},
			},
			want: [][]int{{1}, {2, 3}, {4, 5, 6}},
		},
		{
			name: "Single node",
			root: &TreeNode{Val: 42},
			want: [][]int{{42}},
		},
		{
			name: "Empty tree",
			root: nil,
			want: [][]int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := traversebasic(tt.root)
			if !equal(got, tt.want) {
				t.Errorf("traversebasic() = %v, want %v", got, tt.want)
			}
		})
	}
}
