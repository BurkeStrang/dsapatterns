package levelordertraversal

import "testing"

func Test_maxLevelSum(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want int
	}{
		{
			name: "Example 1: [1,20,3,4,5,null,8]",
			root: &TreeNode{Val: 1,
				Left: &TreeNode{Val: 20,
					Left: &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{Val: 3,
					Right: &TreeNode{Val: 8},
				},
			},
			want: 2,
		},
		{
			name: "Example 2: [10,5,-3,3,2,null,11,3,-2,null,1]",
			root: &TreeNode{Val: 10,
				Left: &TreeNode{Val: 5,
					Left: &TreeNode{Val: 3,
						Left: &TreeNode{Val: 3},
						Right: &TreeNode{Val: -2},
					},
					Right: &TreeNode{Val: 2,
						Right: &TreeNode{Val: 1},
					},
				},
				Right: &TreeNode{Val: -3,
					Right: &TreeNode{Val: 11},
				},
			},
			want: 3,
		},
		{
			name: "Example 3: [5,6,7,8,null,null,9,null,null,10]",
			root: &TreeNode{Val: 5,
				Left: &TreeNode{Val: 6,
					Left: &TreeNode{Val: 8,
						Left: &TreeNode{Val: 10},
					},
				},
				Right: &TreeNode{Val: 7,
					Right: &TreeNode{Val: 9},
				},
			},
			want: 3,
		},
		{
			name: "Single node",
			root: &TreeNode{Val: 42},
			want: 1,
		},
		{
			name: "Negative values",
			root: &TreeNode{Val: -1,
				Left: &TreeNode{Val: -2},
				Right: &TreeNode{Val: -3},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxLevelSum(tt.root)
			if got != tt.want {
				t.Errorf("maxLevelSum() = %v, want %v", got, tt.want)
			}
		})
	}
}

