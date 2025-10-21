package treebfs

import "testing"

func Test_connectall(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want []int
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
			want: []int{1, 2, 3, 4, 5, 6, 7},
		},
		{
			name: "Example 2",
			root: &TreeNode{
				Val: 12,
				Left: &TreeNode{
					Val:  7,
					Left: &TreeNode{Val: 9},
				},
				Right: &TreeNode{
					Val:   1,
					Left:  &TreeNode{Val: 10},
					Right: &TreeNode{Val: 5},
				},
			},
			want: []int{12, 7, 1, 9, 10, 5},
		},
		{
			name: "Empty tree",
			root: nil,
			want: []int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			gotRoot := connectall(tt.root)
			got := flattenNext(gotRoot)
			if !equalIntSlices(got, tt.want) {
				t.Errorf("connectall() = %v, want %v", got, tt.want)
			}
		})
	}
}

// flattenNext traverses the tree using Next pointers and returns values in order.
func flattenNext(root *TreeNode) []int {
	var result []int
	curr := root
	for curr != nil {
		result = append(result, curr.Val)
		curr = curr.Next
	}
	return result
}

// equalIntSlices compares two int slices for equality.
func equalIntSlices(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
