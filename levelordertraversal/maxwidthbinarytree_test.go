package levelordertraversal
import "testing"

func Test_widthOfBinaryTree(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want int
	}{
		{
			name: "Example 1: [1,2,3,4,null,null,5]",
			root: &TreeNode{Val: 1,
				Left: &TreeNode{Val: 2,
					Left: &TreeNode{Val: 4},
				},
				Right: &TreeNode{Val: 3,
					Right: &TreeNode{Val: 5},
				},
			},
			want: 4,
		},
		{
			name: "Example 2: [1,2,3,4,null,5,6,null,7]",
			root: &TreeNode{Val: 1,
				Left: &TreeNode{Val: 2,
					Left: &TreeNode{Val: 4,
						Right: &TreeNode{Val: 7},
					},
					Right: nil,
				},
				Right: &TreeNode{Val: 3,
					Left:  &TreeNode{Val: 5},
					Right: &TreeNode{Val: 6},
				},
			},
			want: 4,
		},
		{
			name: "Example 3: [1,2,null,3,4,null,null,5]",
			root: &TreeNode{Val: 1,
				Left: &TreeNode{Val: 2,
					Left: &TreeNode{Val: 3,
						Left: &TreeNode{Val: 5},
					},
					Right: &TreeNode{Val: 4},
				},
			},
			want: 2,
		},
		{
			name: "Single node",
			root: &TreeNode{Val: 42},
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
			got := widthOfBinaryTree(tt.root)
			if got != tt.want {
				t.Errorf("widthOfBinaryTree() = %v, want %v", got, tt.want)
			}
		})
	}
}
