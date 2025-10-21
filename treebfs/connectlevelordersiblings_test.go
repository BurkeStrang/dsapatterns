package treebfs

import "testing"

func Test_connect(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want [][]int // expected level order traversal using Next pointers
	}{
		{
			name: "Example 1",
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val: 2,
					Left: &TreeNode{Val: 4},
					Right: &TreeNode{Val: 5},
				},
				Right: &TreeNode{
					Val: 3,
					Left: &TreeNode{Val: 6},
					Right: &TreeNode{Val: 7},
				},
			},
			want: [][]int{
				{1},
				{2, 3},
				{4, 5, 6, 7},
			},
		},
		{
			name: "Example 2",
			root: &TreeNode{
				Val: 12,
				Left: &TreeNode{
					Val: 7,
					Left: &TreeNode{Val: 9},
				},
				Right: &TreeNode{
					Val: 1,
					Left: &TreeNode{Val: 10},
					Right: &TreeNode{Val: 5},
				},
			},
			want: [][]int{
				{12},
				{7, 1},
				{9, 10, 5},
			},
		},
		{
			name: "Empty tree",
			root: nil,
			want: [][]int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			gotRoot := connect(tt.root)
			got := levelOrderNext(gotRoot)
			if !equal(got, tt.want) {
				t.Errorf("connect() = %v, want %v", got, tt.want)
			}
		})
	}
}

// levelOrderNext traverses the tree using Next pointers and returns values level by level.
func levelOrderNext(root *TreeNode) [][]int {
	var result [][]int
	for root != nil {
		var level []int
		curr := root
		var nextLevel *TreeNode
		for curr != nil {
			level = append(level, curr.Val)
			if nextLevel == nil {
				if curr.Left != nil {
					nextLevel = curr.Left
				} else if curr.Right != nil {
					nextLevel = curr.Right
				}
			}
			curr = curr.Next
		}
		result = append(result, level)
		root = nextLevel
	}
	if len(result) == 1 && len(result[0]) == 0 {
		return [][]int{}
	}
	return result
}
