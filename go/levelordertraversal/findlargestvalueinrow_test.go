package levelordertraversal

import "testing"

func Test_largestValues(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want []int
	}{
		{
			name: "Example 1",
			root: &TreeNode{Val: 1, Left: &TreeNode{Val: 2, Left: &TreeNode{Val: 4}, Right: &TreeNode{Val: 5}}, Right: &TreeNode{Val: 3, Right: &TreeNode{Val: 6}}},
			want: []int{1, 3, 6},
		},
		{
			name: "Example 2",
			root: &TreeNode{Val: 7, Left: &TreeNode{Val: 4, Left: &TreeNode{Val: 2, Right: &TreeNode{Val: 3}}, Right: &TreeNode{Val: 5}}, Right: &TreeNode{Val: 8, Right: &TreeNode{Val: 9}}},
			want: []int{7, 8, 9, 3},
		},
		{
			name: "Example 3",
			root: &TreeNode{Val: 10, Left: &TreeNode{Val: 5}},
			want: []int{10, 5},
		},
		{
			name: "Empty tree",
			root: nil,
			want: []int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := largestValues(tt.root)
			if !equal(got, tt.want) {
				t.Errorf("largestValues() = %v, want %v", got, tt.want)
			}
		})
	}
}
