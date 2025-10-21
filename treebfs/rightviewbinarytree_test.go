package treebfs

import "testing"

func Test_rightView(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want []int
	}{
		{
			name: "Example 1",
			root: makeTree([]*int{intPtr(1), intPtr(2), intPtr(3), intPtr(4), intPtr(5), intPtr(6), intPtr(7)}),
			want: []int{1, 3, 7},
		},
		{
			name: "Example 2",
			root: makeTree([]*int{intPtr(12), intPtr(7), intPtr(1), nil, intPtr(9), intPtr(10), intPtr(5), nil, intPtr(3)}),
			want: []int{12, 1, 5, 3},
		},
		{
			name: "Example 3",
			root: makeTree([]*int{intPtr(8), intPtr(4), intPtr(9), intPtr(3), nil, nil, intPtr(10), intPtr(2)}),
			want: []int{8, 9, 10, 2},
		},
		{
			name: "Empty tree",
			root: nil,
			want: []int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := rightView(tt.root)
			if !equalIntSlices(got, tt.want) {
				t.Errorf("rightView() = %v, want %v", got, tt.want)
			}
		})
	}
}

// Helper functions for tests

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
