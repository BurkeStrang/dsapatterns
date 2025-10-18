package bfs_test

import(
	"dsapatterns/bfs"
	"testing"
)

func TestFindSuccessor(t *testing.T) {
	tests := []struct {
		name string
		root *bfs.TreeNode
		key  int
		want int // compare by value, not pointer
	}{
		{
			name: "Example 1",
			root: &bfs.TreeNode{
				Val: 1,
				Left: &bfs.TreeNode{
					Val:   2,
					Left:  &bfs.TreeNode{Val: 4},
					Right: &bfs.TreeNode{Val: 5},
				},
				Right: &bfs.TreeNode{Val: 3},
			},
			key:  3,
			want: 4,
		},
		{
			name: "Example 2",
			root: &bfs.TreeNode{
				Val: 12,
				Left: &bfs.TreeNode{
					Val:   7,
					Left:  &bfs.TreeNode{Val: 9},
				},
				Right: &bfs.TreeNode{
					Val:   1,
					Left:  &bfs.TreeNode{Val: 10},
					Right: &bfs.TreeNode{Val: 5},
				},
			},
			key:  9,
			want: 10,
		},
		{
			name: "Example 3",
			root: &bfs.TreeNode{
				Val: 12,
				Left: &bfs.TreeNode{
					Val:   7,
					Left:  &bfs.TreeNode{Val: 9},
				},
				Right: &bfs.TreeNode{
					Val:   1,
					Left:  &bfs.TreeNode{Val: 10},
					Right: &bfs.TreeNode{Val: 5},
				},
			},
			key:  12,
			want: 7,
		},
		{
			name: "No successor (last node)",
			root: &bfs.TreeNode{
				Val: 1,
				Left: &bfs.TreeNode{Val: 2},
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
			got := bfs.FindSuccessor(tt.root, tt.key)
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
