package treebfs

import "testing"

func Test_levelAverage(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want []float64
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
			want: []float64{1, 2.5, 5.5},
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
			want: []float64{12, 4, 8},
		},
		{
			name: "Empty tree",
			root: nil,
			want: []float64{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := levelAverage(tt.root)
			if !equalFloatSlices(got, tt.want) {
				t.Errorf("levelAverage() = %v, want %v", got, tt.want)
			}
		})
	}
}
