package treebfs

import(
	"testing"
)

func TestFindSuccessor(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		key  int
		want int // compare by value, not pointer
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
				Right: &TreeNode{Val: 3},
			},
			key:  3,
			want: 4,
		},
		{
			name: "Example 2",
			root: &TreeNode{
				Val: 12,
				Left: &TreeNode{
					Val:   7,
					Left:  &TreeNode{Val: 9},
				},
				Right: &TreeNode{
					Val:   1,
					Left:  &TreeNode{Val: 10},
					Right: &TreeNode{Val: 5},
				},
			},
			key:  9,
			want: 10,
		},
		{
			name: "Example 3",
			root: &TreeNode{
				Val: 12,
				Left: &TreeNode{
					Val:   7,
					Left:  &TreeNode{Val: 9},
				},
				Right: &TreeNode{
					Val:   1,
					Left:  &TreeNode{Val: 10},
					Right: &TreeNode{Val: 5},
				},
			},
			key:  12,
			want: 7,
		},
		{
			name: "No successor (last node)",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{Val: 2},
			},
			key:  2,
			want: 0, // nil successor
		},
		{
			name: "Empty tree",
			root: nil,
			key:  1,
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := FindSuccessor(tt.root, tt.key)
			var gotVal int
			if got != nil {
				gotVal = got.Val
			}
			if gotVal != tt.want {
				t.Errorf("FindSuccessor() = %v, want %v", gotVal, tt.want)
			}
		})
	}
}
