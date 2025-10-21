package treedfs

import "testing"

func Test_hasPath(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		sum  int
		want bool
	}{
		{
			name: "Example 1",
			root: makeTree([]*int{intPtr(1), intPtr(2), intPtr(3), intPtr(4), intPtr(5), intPtr(6), intPtr(7)}),
			sum:  10,
			want: true,
		},
		{
			name: "Example 2",
			root: makeTree([]*int{intPtr(12), intPtr(7), intPtr(1), intPtr(9), nil, intPtr(10), intPtr(5)}),
			sum:  23,
			want: true,
		},
		{
			name: "Example 3",
			root: makeTree([]*int{intPtr(12), intPtr(7), intPtr(1), intPtr(9), nil, intPtr(10), intPtr(5)}),
			sum:  16,
			want: false,
		},
		{
			name: "Empty tree",
			root: nil,
			sum:  0,
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := hasPath(tt.root, tt.sum)
			if got != tt.want {
				t.Errorf("hasPath() = %v, want %v", got, tt.want)
			}
		})
	}
}

// Helpers for tests

func intPtr(v int) *int { return &v }

// makeTree builds a binary tree from a level-order slice of *int (nil for missing nodes).
func makeTree(vals []*int) *TreeNode {
	if len(vals) == 0 || vals[0] == nil {
		return nil
	}

	root := &TreeNode{Val: *vals[0]}
	queue := []*TreeNode{root}
	i := 1

	for len(queue) > 0 && i < len(vals) {
		node := queue[0]
		queue = queue[1:]

		// Process left child
		if i < len(vals) {
			if vals[i] != nil {
				node.Left = &TreeNode{Val: *vals[i]}
				queue = append(queue, node.Left)
			}
			i++
		}

		// Process right child
		if i < len(vals) {
			if vals[i] != nil {
				node.Right = &TreeNode{Val: *vals[i]}
				queue = append(queue, node.Right)
			}
			i++
		}
	}

	return root
}
