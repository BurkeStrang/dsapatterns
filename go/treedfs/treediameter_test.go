package treedfs

import "testing"

func Test_findDiameter(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want int
	}{
		{
			name: "Single node",
			root: &TreeNode{Val: 1},
			want: 0,
		},
		{
			name: "Simple tree",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val:   2,
					Left:  &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{Val: 3},
			},
			want: 4, // Path: 4-2-1-3 or 5-2-1-3
			//            1
			//           / \
			//          2   3
			//         / \
			//        4   5
		},
		{
			name: "Linear tree",
			root: &TreeNode{
				Val: 1,
				Right: &TreeNode{
					Val: 2,
					Right: &TreeNode{
						Val: 3,
					},
				},
				Left: &TreeNode{
					Val: 4,
				},
			},
			want: 4, // Path: 1-2-3
			//       1
			//      / \
			//     4   2
			//          \
			//           3
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findDiameter(tt.root)
			if got != tt.want {
				t.Errorf("findDiameter() = %v, want %v", got, tt.want)
			}
		})
	}
}
