package treedfs
// TreeNode struct
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
	Next  *TreeNode
}


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

// equal compares two [][]int slices for equality.
func equal(a, b [][]int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if len(a[i]) != len(b[i]) {
			return false
		}
		for j := range a[i] {
			if a[i][j] != b[i][j] {
				return false
			}
		}
	}
	return true
}
