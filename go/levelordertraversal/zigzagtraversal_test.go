package levelordertraversal

import "testing"

func Test_traverseZigZag(t *testing.T) {

	tests := []struct {
		name string
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
			want: [][]int{{1}, {3, 2}, {4, 5, 6}},
		},
		{
			name: "Example 2: [7,4,8,2,5,null,9,null,3]",
			root: &TreeNode{Val: 7,
				Left: &TreeNode{Val: 4,
					Left: &TreeNode{Val: 2,
						Right: &TreeNode{Val: 3},
					},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{Val: 8,
					Right: &TreeNode{Val: 9},
				},
			},
			want: [][]int{{7}, {8, 4}, {2, 5, 9}, {3}},
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
			got := traverseZigZag(tt.root)
			if !equal(got, tt.want) {
				t.Errorf("traverseZigZag() = %v, want %v", got, tt.want)
			}
		})
	}
}
