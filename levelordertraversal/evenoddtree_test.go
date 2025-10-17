package levelordertraversal

import "testing"

func Test_isEvenOddTree(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want bool
	}{
		{
			name: "Example 1: Valid Even-Odd Tree",
			root: &TreeNode{Val: 1,
				Left: &TreeNode{Val: 10,
					Left: &TreeNode{Val: 3},
					Right: &TreeNode{Val: 7},
				},
				Right: &TreeNode{Val: 4},
			},
			want: true,
		},
		{
			name: "Example 2: Invalid Even-Odd Tree (odd values at level 1)",
			root: &TreeNode{Val: 5,
				Left: &TreeNode{Val: 9,
					Left: &TreeNode{Val: 12},
				},
				Right: &TreeNode{Val: 3,
					Right: &TreeNode{Val: 8},
				},
			},
			want: false,
		},
		{
			name: "Example 3: Invalid Even-Odd Tree (even values at even level)",
			root: &TreeNode{Val: 7,
				Left: &TreeNode{Val: 10,
					Left: &TreeNode{Val: 12},
					Right: &TreeNode{Val: 8},
				},
				Right: &TreeNode{Val: 2},
			},
			want: false,
		},
		{
			name: "Single node (odd value at level 0)",
			root: &TreeNode{Val: 1},
			want: true,
		},
		{
			name: "Single node (even value at level 0)",
			root: &TreeNode{Val: 2},
			want: false,
		},
		{
			name: "Empty tree",
			root: nil,
			want: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isEvenOddTree(tt.root)
			if got != tt.want {
				t.Errorf("isEvenOddTree() = %v, want %v", got, tt.want)
			}
		})
	}
}

