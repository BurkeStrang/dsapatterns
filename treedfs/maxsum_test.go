package treedfs

import "testing"

func TestSolution_findMaximumPathSum(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want int
	}{
		{
			name: "simple tree",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val: 2,
				},
				Right: &TreeNode{
					Val: 3,
				},
			},
			want: 6, // 2 + 1 + 3
		},
		{
			name: "tree with negative values",
			root: &TreeNode{
				Val: -10,
				Left: &TreeNode{
					Val: 9,
				},
				Right: &TreeNode{
					Val: 20,
					Left: &TreeNode{
						Val: 15,
					},
					Right: &TreeNode{
						Val: 7,
					},
				},
			},
			want: 42, // 15 + 20 + 7
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := NewSolution()
			got := s.findMaximumPathSum(tt.root)
			if got != tt.want {
				t.Errorf("findMaximumPathSum() = %v, want %v", got, tt.want)
			}
		})
	}
}

